// define the pins for the LEDs
int ledPin1 = 3;
int ledPin2 = 6;
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  Serial.print("Value: ");
  Serial.print(value);
  Serial.print("   ");

  Serial.print("Water Level: ");

  if (value == 0) {
    Serial.println("Empty");
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  } else if (value > 1 && value < 350) {
    Serial.println("Low");
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
  } else if (value > 350 && value < 510) {
    Serial.println("Medium");
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  } else if (value > 510) {
    Serial.println("High");
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  }
  delay(1000);  // Adjust the delay as needed
}
