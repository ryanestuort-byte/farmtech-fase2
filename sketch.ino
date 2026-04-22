#include <DHTesp.h>

DHTesp dht;

int botaoN = 14;
int botaoP = 27;
int botaoK = 26;

int rele = 25;
int ldr = 34;

void setup() {
  Serial.begin(115200);

  pinMode(botaoN, INPUT_PULLUP);
  pinMode(botaoP, INPUT_PULLUP);
  pinMode(botaoK, INPUT_PULLUP);

  pinMode(rele, OUTPUT);

  dht.setup(15, DHTesp::DHT22);
}

void loop() {

  float umidade = dht.getHumidity();
  int luz = analogRead(ldr);

  bool N = digitalRead(botaoN) == LOW;
  bool P = digitalRead(botaoP) == LOW;
  bool K = digitalRead(botaoK) == LOW;

  int total = N + P + K;

  if (umidade < 50 && total >= 2) {
    digitalWrite(rele, HIGH);
    Serial.println("BOMBA LIGADA");
  } else {
    digitalWrite(rele, LOW);
    Serial.println("BOMBA DESLIGADA");
  }

  delay(2000);
}
