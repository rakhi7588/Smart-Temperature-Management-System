// RGB LED pins
int redPin = 9;
int greenPin = 8;
int bluePin = 10;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  //  temperature reading 
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100;

  // Potentiometer
  int potValue = analogRead(A1);

  // Threshold (25°C to 35°C)
  float threshold = 25 + (potValue / 1023.0) * 10;

  // Print
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" | Threshold: ");
  Serial.println(threshold);

  // LED logic
  if (temperature < threshold - 0.5) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  else if (temperature > threshold + 0.5) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }

  delay(500);
}