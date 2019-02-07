#define BLINK_ALL 0xFF;
#define SEGMENTS_OFF 0x00;

void setup() {
  DDRD = 0xFF; //PORT D is set as output
}

void loop() {
  PORTD = BLINK_ALL;
  delay(500);
  PORTD = SEGMENTS_OFF;
  delay(500);
}
