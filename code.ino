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
  pinMode(pwn_pin, OUTPUT);
}

void loop() {

  // find first correct values of buttonValue
  buttonValue = analogRead(A0);

  if (buttonValue >= 1010 && buttonValue <= 1015) {
    value = 100;
  } else if (buttonValue >= 1000 && buttonValue <= 1008) {
    value = 150;
  } else if (buttonValue >= 990  && buttonValue <= 998) {
    value = 200;
  }

  if (Serial.available() > 0) {
    value = Serial.parseInt();
    Serial.println(value);
  }
  analogWrite(pwn_pin, value);
}
