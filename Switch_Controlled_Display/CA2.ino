//defining the values to be dislayed in seven segment
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
#define CHAR_A 0x77
#define CHAR_B 0x7C
#define CHAR_C 0x39
#define CHAR_D 0x5E
#define CHAR_E 0x79
#define CHAR_F 0x71

//defining the input values
#define INPUT_0 0x0F
#define INPUT_1 0x0E
#define INPUT_2 0x0D
#define INPUT_3 0x0C
#define INPUT_4 0x0B
#define INPUT_5 0x0A
#define INPUT_6 0x09
#define INPUT_7 0x08
#define INPUT_8 0x07
#define INPUT_9 0x06
#define INPUT_10 0x05
#define INPUT_11 0x04
#define INPUT_12 0x03
#define INPUT_13 0x02
#define INPUT_14 0x01
#define INPUT_15 0x00

void setup() {
  DDRB = 0x00; //PORB B is set as input
  PORTB = 0xFF; //Activate pull up resistors in portB
  DDRD = 0xFF; //PORT D is set as output
}

void loop() {
  unsigned char x = PINB;
  x &= 0x0F; //masking the upper bits of PINB

  switch (x) {
    case INPUT_0:
      PORTD = NUM_0;
      break;
    case INPUT_1:
      PORTD = NUM_1;
      break;
    case INPUT_2:
      PORTD = NUM_2;
      break;
    case INPUT_3:
      PORTD = NUM_3;
      break;
    case INPUT_4:
      PORTD = NUM_4;
      break;
    case INPUT_5:
      PORTD = NUM_5;
      break;
    case INPUT_6:
      PORTD = NUM_6;
      break;
    case INPUT_7:
      PORTD = NUM_7;
      break;
    case INPUT_8:
      PORTD = NUM_8;
      break;
    case INPUT_9:
      PORTD = NUM_9;
      break;
    case INPUT_10:
      PORTD = CHAR_A;
      break;
    case INPUT_11:
      PORTD = CHAR_B;
      break;
    case INPUT_12:
      PORTD = CHAR_C;
      break;
    case INPUT_13:
      PORTD = CHAR_D;
      break;
    case INPUT_14:
      PORTD = CHAR_E;
      break;
    case INPUT_15:
      PORTD = CHAR_F;
      break;
    default:
      PORTD = NUM_0;
      break;
  }
}
