#include<reg52.h>
#define KeyPort P3
#define KeyPort2 P2

unsigned char High, Low;

sbit SPK = P1^2;

unsigned char code freq[][2] = {
    0x43,0xF2, // C     0
    0xC2,0xF3, // D     1
    0x18,0xF5, // E     2
    0xB0,0xF5, // F     3
    0xD1,0xF6, // G     4
    0xD2,0xF7, // A     5
    0xB7,0xF8, // B     6
    0x1E,0xF9, // C`    7

    0x1E,0xF9, // C`    8
    0xDF,0xF9, // D`    9
    0x8A,0xFA, // E`    10
    0xD8,0xFA, // F`    11
    0x69,0xFB, // G`    12
    0xE9,0xFB, // A`    13
    0x5B,0xFC, // B`    14
    0x90,0xFC, // C``   15

    0x90,0xFC, // C``   15+1
    0xB5,0xFD, // G``   15+2
    0xF0,0xFC, // D``   15+3
    0xF5,0xFD, // A``   15+4
    0x45,0xFD, // E``   25+5
    0x2C,0xFE, // B``   25+6
    0x71,0xFD, // F``   25+7
    0x48,0xFE, // C```  25+8
}; 

void Init_Timer0(void);

unsigned char KeyScan (void) {
  unsigned char cord_h, cord_l;
  KeyPort2 = 0x0f;
  cord_h = KeyPort2&0x0f;
  if (cord_h != 0x0f) {
    //display(cnt);;
    if((KeyPort2 & 0x0f) != 0x0f) {
      cord_h = KeyPort2 & 0x0f;
      KeyPort2 = cord_h | 0xf0;
      cord_l = KeyPort2 & 0xf0;

      while((KeyPort2 & 0xf0) != 0xf0)
        return(cord_h + cord_l);
    }
  }
  return(0xff);
}

unsigned char KeyPro (void) {
    switch(KeyScan()) //1..16
    {
        case 0x7e: return 1; break; //0
        case 0x7d: return 2; break; //1
        case 0x7b: return 3; break; //2
        case 0x77: return 4; break; //3
        case 0xbe: return 5; break; //4
        case 0xbd: return 6; break; //5
        case 0xbb: return 7; break; //6
        case 0xb7: return 8; break; //7
        case 0xde: return 9; break; //8
        case 0xdd: return 10; break; //9
        case 0xdb: return 11; break; //a
        case 0xd7: return 12; break; //b
        case 0xee: return 13; break; //c
        case 0xed: return 14; break; //d
        case 0xeb: return 15; break; //e
        case 0xe7: return 16; break; //f
        default: return 0; break;
    }
}

void main (void) {
  unsigned char num;
  unsigned char num1;
  Init_Timer0();
  SPK = 0;
  while(1) {
    switch(KeyPort) { //1..8
      case 0xfe: num = 17; break;
      case 0xfd: num = 18; break;
      case 0xfb: num = 19; break;
      case 0xf7: num = 20; break;
      case 0xef: num = 21; break;
      case 0xdf: num = 22; break;
      case 0xbf: num = 23; break;
      case 0x7f: num = 24; break;
      default: num = 0; break;
    }
    num1 = KeyPro();
    if(num1 == 0 && num == 0) {
      TR0 = 0;
      SPK = 0;
    } else {
      if(num1>num) {
        High = freq[num1-1][1];
        Low = freq[num1-1][0];
        TR0 = 1;
      }
      if(num1<num) {
        High = freq[num-1][1];
        Low = freq[num-1][0];
        TR0 = 1;
      }
    }
  }
}

void Init_Timer0(void) {
    TMOD |= 0x01;
    EA = 1;
    ET0 = 1;
  //TR0 = 1;
}

void Timer0_isr(void) interrupt 1 {
    TH0 = High;
    TL0 = Low;
    SPK = !SPK;
}
