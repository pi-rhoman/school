
int light = 100;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, INPUT);
  light = 100;
}

void go_to_pin(int pin) {
  // turn off all other pins and then turn the given pin on
  for (int i=1;i<6;++i){
    digitalWrite(i, LOW);
  }
  digitalWrite(pin, HIGH);
}
// the loop function runs over and over again forever
void loop() {

  
  light = analogRead(9);
  for (int i=1;i<6;++i){
    go_to_pin(i);
    delay(light);
  }
}
