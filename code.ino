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

void setup() {
  Serial.begin(9600);
  pinMode(pwn_pin, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.parseInt();
    Serial.println(value);
  }
  analogWrite(pwn_pin, value);

}
