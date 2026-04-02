/**
 * @file sketch.ino
 * @brief Control de LED mediante BLE (Pin 13)
 * @version 1.0
 */

const int LED_PIN = 13;

void setup() {
  // Inicialización de comunicación serial a 9600 baudios (estándar HM-10)
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    // Validación de entrada estricta
    switch(command) {
      case '1':
        digitalWrite(LED_PIN, HIGH);
        break;
      case '0':
        digitalWrite(LED_PIN, LOW);
        break;
      default:
        // Ignorar caracteres de ruido o malformados
        break;
    }
  }
}
