/*

  PIN ----[R10k]----|----------() VOUT
                   |
                 ------
                  10uF
                 ------
                   |
                   |
  GND --------------------------- GND

*/
int pwn_pin = 5;
int value = 0;
int buttonValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(pwn_pin, OUTPUT);

  pinMode(2, OUTPUT); // LED 1
  pinMode(3, OUTPUT); // LED 2
  pinMode(4, OUTPUT); // LED 3
}

void loop() {

  buttonValue = analogRead(A0);
  Serial.println(buttonValue);
  if (buttonValue >= 100 && buttonValue <= 140) {
    value = 100;
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    Serial.println("LED 1");
  } else if (buttonValue >= 60 && buttonValue <= 90) {
    value = 150;
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    Serial.println("LED 2");
  } else if (buttonValue >= 10  && buttonValue <= 40) {
    value = 200;
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    Serial.println("LED 3");
  }

  if (Serial.available() > 0) {
    value = Serial.parseInt();
    Serial.println(value);
  }
  analogWrite(pwn_pin, value);

  delay(100);
}
