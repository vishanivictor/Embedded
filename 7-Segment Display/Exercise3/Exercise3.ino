#define NUM_0 0x3F
#define NUM_1 0x06
#define NUM_2 0x5B
#define NUM_3 0x4F
#define NUM_4 0x66
#define NUM_5 0x6D
#define NUM_6 0x7D
#define NUM_7 0x07
#define NUM_8 0x7F
#define NUM_9 0x6F

int myArray[10] = {NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9} ;

void setup() {
  DDRD = 0xFF;
}

void loop() {
  for (int i = 0; i < 10; i++) {
    PORTD = myArray[i];
    delay(500);
  }
}
