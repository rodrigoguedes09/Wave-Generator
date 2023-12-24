#include <ESP8266WiFi.h>

const int r2rPins[] = {16, 5, 4, 0, 2, 14, 12, 13};

int senoidWave[] = {255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0}; // Onda senoidal
int quadradoWave[] = {0, 32, 64, 96, 128, 160, 192, 224, 255, 224, 192, 160, 128, 96, 64, 32, 0}; // Onda quadrada
int triangularWave[] = {255, 100, 30, 0, 30, 100, 255, 255, 100, 30, 0, 30, 100, 255, 255, 100, 30, 0, 30, 100, 255, 255, 100, 30, 0, 30, 100, 255}; // Onda triangular (exemplo)

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(r2rPins[i], OUTPUT);
  }

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}

void loop() {
  Serial.println("MENU");
  Serial.println("[1] Gera onda senoide");
  Serial.println("[2] Gera onda triangular");
  Serial.println("[3] Gera onda quadrado");
  Serial.println("[4] Gera onda serra");

  while (!Serial.available()) {
    delay(100);
  }

  char choice = Serial.read();

  switch (choice) {
    case '1':
      generateWave(senoidWave, sizeof(senoidWave) / sizeof(senoidWave[0]), true);
      break;
    case '2':
      generateWave(triangularWave, sizeof(triangularWave) / sizeof(triangularWave[0]), false);
      break;
    case '3':
      generateWave(quadradoWave, sizeof(quadradoWave) / sizeof(quadradoWave[0]), false);
      break;
  }
}

void generateWave(int waveform[], int length, bool isSenoidWave) {
  const int numCycles = 5;

  for (int cycle = 0; cycle < numCycles; cycle++) {
    for (int i = 0; i < length; i++) {
      if (isSenoidWave) {
        digitalWrite(r2rPins[i % 8], waveform[i] > 0 ? HIGH : LOW);
      } else {
        digitalWrite(r2rPins[i % 8], waveform[i]);
      }
      delay(50);
    }
  }
}
