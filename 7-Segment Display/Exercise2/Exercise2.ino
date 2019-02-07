#define SEG_A 0x01
#define SEG_B 0x02
#define SEG_C 0x04
#define SEG_D 0x08
#define SEG_E 0x10
#define SEG_F 0x20
#define SEG_G 0x40
#define DECIMAL 0x80

int myArray[10] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, DECIMAL} ;

void setup() {
  DDRD = 0xFF;
}

void loop() {
  for (int i = 0; i < 8; i++) {
    PORTD = myArray[i];
    delay(500);
  }
}
