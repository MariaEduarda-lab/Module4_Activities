class Led {
private:
  int porta; // Existe para que a porta seja setada e inalterada.

public:
  // Construtor: Configura o pino
  Led(int p) {
    porta = p;
    pinMode(porta, OUTPUT);
  }

  void ligar() { // Criar método ligar para ser aplicado em cada led
    digitalWrite(porta, HIGH);
  }

  void desligar() { // Criar método desligar para ser aplicado em cada led
    digitalWrite(porta, LOW);
  }

  void ligarPor(long milissegundos) { // Definir o tempo pelo qual o led será ligado
    ligar();
    delay(milissegundos);
    desligar();
  }
};

// Os objetos são criados diretamente na memória do programa.
Led ledVermelho(12); // Objeto Vermelho existe no endereço X
Led ledAmarelo(11); // Objeto Amarelo existe no endereço Y
Led ledVerde(10);   // Objeto Verde existe no endereço Z

// --- 1. Declaração dos PONTEIROS para os objetos Led ---
// Eles agora vão apontar para os objetos já existentes (ledVermelho, etc.)
Led* ledVermelhoPtr;
Led* ledAmareloPtr;
Led* ledVerdePtr;


void setup() {

  // 2. Atribuição dos endereços dos objetos aos ponteiros 
  // O operador '&' (endereço de) pega o endereço de memória da variável
  ledVermelhoPtr = &ledVermelho;
  ledAmareloPtr = &ledAmarelo;
  ledVerdePtr = &ledVerde;
}

void loop() {

  // 3. Acessando os Métodos via Ponteiro (Continua usando '->')
  // O acesso permanece o mesmo: usamos '->' porque estamos lidando com PONTEIROS.
  
  ledVerdePtr->ligarPor(4000);
  
  ledVermelhoPtr->ligarPor(6000); 

  ledAmareloPtr->ligarPor(2000);
}