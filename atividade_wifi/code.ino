#include <WiFi.h>
#include <PubSubClient.h>

// --- Configurações da Rede Wi-Fi ---
const char* ssid = "id";
const char* password = "password";

// --- Configurações do Adafruit IO ---
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "user"
#define AIO_KEY         "key"

// O feed do Adafruit IO -broker - onde você publicará os dados.
// Deve ser no formato: AIO_USERNAME/feeds/nome-do-seu-feed
const char *AIO_FEED_DBM = "feed; 

// --- Configurações do MQTT ---
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

// Função para reconectar ao Adafruit IO
void reconnect() {
  // Loop enquanto não estiver conectado
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT com Adafruit IO...");

    // Tenta conectar, usando o AIO_USERNAME e AIO_KEY como credenciais
    if (client.connect("ESP32Client", AIO_USERNAME, AIO_KEY)) {
      Serial.println("conectado!");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      // Espera 5 segundos antes de tentar novamente
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(AIO_SERVER, AIO_SERVERPORT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  // Publica a cada 5 segundos (5000 milissegundos)
  if (now - lastMsg > 5000) { 
    lastMsg = now;

    // --- 1. Medição da Potência do Sinal Wi-Fi ---
    // A função WiFi.rssi() retorna a Received Signal Strength Indicator (RSSI) em dBm
    long rssi = WiFi.RSSI();
    Serial.print("Potência do Sinal (dBm): ");
    Serial.println(rssi);

    // --- 2. Preparação e Publicação da Mensagem ---
    
    // Converte o valor de long (rssi) para uma string (msg) para enviar via MQTT
    // O Adafruit IO aceita valores inteiros ou decimais.
    String payload = String(rssi); 
    payload.toCharArray(msg, 50);

    Serial.print("Publicando no feed ");
    Serial.print(AIO_FEED_DBM);
    Serial.print(": ");
    Serial.println(msg);

    // Publica a mensagem no tópico MQTT
    if (client.publish(AIO_FEED_DBM, msg)) {
      Serial.println("Publicação enviada com sucesso.");
    } else {
      Serial.println("Erro ao enviar a publicação.");
    }
  }
}