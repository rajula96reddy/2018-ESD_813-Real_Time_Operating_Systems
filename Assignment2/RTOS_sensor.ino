int pin_1 = 1;
int pin_2 = 2;
int pin_3 = 3;
int pin_4 = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
//  pinMode(pin_5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_4, 1);
//  delay(100);
  digitalWrite(pin_4, 0);
  digitalWrite(pin_1, random(0,2));
  digitalWrite(pin_2, random(0,2));
  digitalWrite(pin_3, random(0,2));
//  digitalWrite(pin_4, 1);
  delay(5000);
}
