class Policia {
  int *r, *w, *b;
  bool ativo;

public:
  Policia(int *red, int *white, int *blue) {
    r = red;
    w = white;
    b = blue;
    ativo = false;
  }

  void start() {
    ativo = true;
  }

  void stop() {
    ativo = false;
    digitalWrite(*r, LOW);
    digitalWrite(*w, LOW);
    digitalWrite(*b, LOW);
  }

  void executar() {
    if (ativo) {
      digitalWrite(*r, HIGH);
      delay(200);
      digitalWrite(*r, LOW);

      digitalWrite(*w, HIGH);
      delay(200);
      digitalWrite(*w, LOW);

      digitalWrite(*b, HIGH);
      delay(200);
      digitalWrite(*b, LOW);
    }
  }
};

int red = 8;
int white = 7;
int blue = 6;

Policia pol(&red, &white, &blue);

void setup() {
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(blue, OUTPUT);

  Serial.begin(9600);
  Serial.println("Digite C para começar e T para terminar");
}

void loop() {
  pol.executar();

  if (Serial.available()) {
    String comando = Serial.readStringUntil('\n');
    comando.trim(); // remove espaços e quebras de linha

    Serial.println("Comando recebido: " + comando);

    if (comando == "C" || comando == "c") {
      pol.start();
    }
    else if (comando == "T" || comando == "t") {
      pol.stop();
    }
    else
      Serial.print("Comando não identificado");
  }
}
