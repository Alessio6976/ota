const int sensorPins[5] = {1, 0, 7, 12, A6}; // TX (1), RX (0), D7 (7), D12 (12), A6 (A6)
const char* sensorNames[5] = {"TX", "RX", "D7", "D12", "A6"};

void setup() {
  Serial.begin(9600);

  // Imposta i pin dei sensori come input
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  Serial.println("Inizializzazione completata. In attesa di stato dei sensori...");
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int sensorState = digitalRead(sensorPins[i]);
    Serial.print("Stato sensore ");
    Serial.print(sensorNames[i]);
    Serial.print(": ");
    if (sensorState == HIGH) {
      Serial.println("APERTI");
    } else {
      Serial.println("INTERROTTO");
    }
  }

  delay(1000); // Ritardo di 1 secondo tra le letture
}
