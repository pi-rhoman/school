void setup() {
  // set the portd to be input 
  DDRD  = 0B00000000;
  // set pins 8 and 9 to be output
  DDRB |= 0B00000011;


}

void loop() {
  
  // store port d in unshifted so that it doesn't change between setting green and setting red
  unsigned char unshifted = (PIND);
  unsigned char shifted = (PIND << 1);  

  // two adjacent pins in PIND are HIGH
  boolean green = !!(shifted & unshifted & 0B11111000);
  // two adjacent pins in PIND are LOW
  boolean red = !!(~shifted & ~unshifted & 0B11111100);
  
  // set pin 8 to green
  PORTB ^= (-green ^ PORTB) & (1);
  // set pin 9 to red  
  PORTB ^= (-red ^ PORTB) & 2;
}
