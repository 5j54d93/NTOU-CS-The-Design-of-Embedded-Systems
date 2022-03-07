#include <reg52.h>
#define  BUS  P0

unsigned char code font[10] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 }; 
unsigned char code digit[8] = { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f };
unsigned char code hello[5] = { "HELLO" };

#define ms50 65536-46080  // 11.0592Mhz
#define ms10 65536-10000
#define MAX 10

typedef unsigned char byte;
typedef unsigned int  word;

sbit fontcs = P2^0;
sbit digitcs = P2^1;

unsigned long cnt_end = 100000000;
unsigned long cnt_start = 0;
signed int updowncnt = 1;
unsigned int ms_cnt = 20; //20 次 50ms = 1 sec
unsigned long cnt;
unsigned long pre_cnt;
byte tmp[2];
byte tmp_cnt = 0;
byte buf[MAX];
byte tail = 0;
byte head = 0;
byte ms = 0;

void timer_init() { //timer0
    TMOD = TMOD | 0x01;
    TH0 = ms50/256;
    TL0 = ms50%256;
    TF0 = 0;
    TR0 = 1;
    
    EA = 1;
    ET0 = 1;
}

void uart_init() {
    SCON = 0x50;  // mode 1,8-bit UART
//  PCON = 0x0;   // SMOD = 0;

    TMOD = TMOD | 0x20; //mode 2, timer1 8-bit reload
    TH1 = 0xfd; //bound rate: 9600:11.0592MHz
    TR1 = 1;    //timer1

    RI = 0;
    TI = 0;

    EA  = 1;
    ES = 1;
}

void uart_isr() interrupt 4 { //uart interrupt
  unsigned int tmpsum = 0;
  unsigned int ten = 1;
  unsigned int i = 0;
  byte k;
  
  if (RI == 1) {
    RI = 0;
    k = SBUF;
    tmp[tmp_cnt] = k;
        
    if (k == 'R') {
      cnt = 100000000;
      tail = 0;
      head = 0;
      pre_cnt = 0;
      updowncnt = 1;
      ms_cnt = 20;    
    } else if(k ==  'U') {
      cnt = cnt;
      tail = 0;
      head = 0;
      pre_cnt = cnt;
      updowncnt = 1;
      ms_cnt = ms_cnt;
    } else if(k ==  'D') {
      cnt = cnt;
      tail = 0;
      head = 0;
      pre_cnt = cnt;
      updowncnt = -1;
      ms_cnt = ms_cnt;
    } else if(tmp[0] == 's') {
      tmp_cnt++;
      if(tmp[1] == '1') {
        cnt = cnt;
        tail = 0;
        head = 0;
        pre_cnt = cnt;
        updowncnt = updowncnt;
        ms_cnt = 20;
      } else if(tmp[1] == '2') {
        cnt = cnt;
        tail = 0;
        head = 0;
        pre_cnt = cnt;
        updowncnt = updowncnt;
        ms_cnt = 40;
      }
    } else {
        buf[tail] = k;
        tail++;
        if (tail == MAX) tail = 0;
    }
    if(tmp_cnt==2) tmp_cnt = 0;
  }
}

void timer_isr() interrupt 1 { //timer0 interrupt
  TH0 = ms50/256;
  TL0 = ms50%256;
  TF0 = 0;
  ms++;
  
  if (ms == ms_cnt) {
    ms = 0;
    cnt += updowncnt;
  }
}

void delay (unsigned int d) {
  unsigned int i,j;
  
  for(i=0;i<10;i++)
      for(j=0;j<d;j++);
}

void put_data (unsigned char i, unsigned char j) {
    BUS = 0xff - font[j]; 
    fontcs = 1;
    fontcs = 0;

    BUS = digit[i];
    digitcs = 1;
    digitcs = 0;
}

void display (unsigned long i) {
    unsigned char j;

    for (j=0;j<8;j++) {
      put_data(7-j, i%10);
      delay(5);
      i /= 10;
    }
}

void send_cnt() {
  unsigned long temp;
  byte i, j;
  temp = cnt;
  i = 0;
  
  while (temp != 0) {
      buf[i] = (temp%10) + 0x30;
      temp /= 10;
      i++;
  }
  for (j=i; j>0; j--) {
      SBUF = buf[j-1];
      while(TI != 1);
      TI = 0;
  }
}

void test_send() {
  byte i;

  for (i=0; i<5; i++) {
      SBUF = hello[i];
      while(TI != 1);
      TI = 0;
  }
}

void main() {
    //unsigned char i;
    unsigned char k=0;
    byte j=0;

    cnt=0;
    timer_init();
    uart_init();
    test_send();
  
    while(1) {
      if (head != tail) {
        if (buf[head] == '\r') { //CR ASCii = 0x0D,   \n: 0x0a
            cnt = pre_cnt;
            pre_cnt = 0;
            head++;
            if (head == MAX) head = 0;
            send_cnt();
        } else {
            pre_cnt = pre_cnt * 10 + (buf[head]-0x30);  //'0':0x30, '1': 0x31
            head++;
            if (head == MAX) head = 0;
        }
      }
      display(cnt);
    }
}
