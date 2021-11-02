#define BUZZERPIN 7

#define CFOUR 1911
#define DFOUR 1702
#define EFOUR 1516
#define FFOUR 1431
#define GFOUR 1275
#define AFOUR 1136
#define BFOUR 1012
#define CFIVE 955

short notes[9] = {CFOUR, DFOUR, EFOUR, FFOUR, GFOUR, AFOUR, BFOUR, CFIVE, 0};
char keys[9] = {'z','x','c','v','b','n','m',',', ' '};
void setup() {
  // set the pinmode of the pin the buzzer is connected to 
  pinMode(BUZZERPIN, OUTPUT);
  // start the serial port
  Serial.begin(9600);

}
void loop() {
    if(Serial.available()){
      short incoming_byte = Serial.read();
      play_note(get_note(incoming_byte));

      Serial.println();
    }
  

}
short get_note(char key){  
  // return the note corresponding to the key character entered
  // return 0 if no note corresponds

  
  int i;
  for(i = 0; i < sizeof(keys); i++){
      if(keys[i] == key) return notes[i];
  }
  return 0;
}

void play_note(int f) {
  // play note with period 2f
  if(f>0){
    for(int i=0; i<100; i++){
      digitalWrite(BUZZERPIN, HIGH);
      delayMicroseconds(f);
      digitalWrite(BUZZERPIN, LOW);
      delayMicroseconds(f);
    }
  } else {
    delay(100);
    Serial.println("space pressed");
    
  }

}
