#include "ds1302.h"
#include <reg52.h>
#define DataPort P0
#define KeyPort P3

sbit LATCH1 = P2^2;
sbit LATCH2 = P2^3;
sbit SPK = P1^2; //Buzzer
bit ReadTimeFlag;

unsigned char code dofly_DuanMa[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
unsigned char code dofly_WeiMa[] = { 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f };
unsigned char TempData[8];

unsigned char Trg = 0;
unsigned char Cont = 0;

unsigned char KeyScan(void);
void Display(unsigned char FirstBit, unsigned char Num);
void DelayUs2x(unsigned char t);
void DelayMs(unsigned char t);
void Init_Timer0(void);

void main (void) {
  unsigned char num, displaynum=0;
  unsigned char alarm_closed=1;
  unsigned int i;
  Init_Timer0();
  Ds1302_Init();
  //Ds1302_Write_Time();
  //Ds1302_Write_Time_Alarm();
  while (1) {
    num = KeyScan();
    if(num==8) {
       displaynum++;
       if(displaynum==3)//0°B1°B2
          displaynum=0;
    }
    if(Cont) {
      switch(num)  { //Set Time or Date
        case 1: //Hour +1
            if(displaynum==0) {
                time_buf1[4]++;
                if(time_buf1[4]==24) time_buf1[4] = 0;
                Ds1302_Write_Time();
            } else if(displaynum==1) {
                time_buf2[4]++;
                if(time_buf2[4]==24) time_buf2[4] = 0;
                Ds1302_Write_Time_Alarm();
            }
            break;
        case 3: //Minute +1
            if(displaynum==0) {
                time_buf1[5]++;
                if(time_buf1[5]==60) time_buf1[5] = 0;
                Ds1302_Write_Time();
            } else if(displaynum==1) {
                time_buf2[5]++;
                if(time_buf2[5]==60) time_buf2[5] = 0;
                Ds1302_Write_Time_Alarm();
            }
            break;
        case 5: //Second +1
            if(displaynum==0) {
                time_buf1[6]++;
                if(time_buf1[6]==60) time_buf1[6] = 0;
                Ds1302_Write_Time();
            } else if(displaynum==1) {
                time_buf2[6]++;
                if(time_buf2[6]==60) time_buf2[6] = 0;
                Ds1302_Write_Time_Alarm();
            }
            break;
        case 2: //Year +1
            if(displaynum==2) {
                time_buf1[1]++;
                if(time_buf1[1]==99) time_buf1[1] = 0;
                Ds1302_Write_Time();

            }
            break;
        case 4: //Month +1
            if(displaynum==2) {
                time_buf1[2]++;
                if(time_buf1[2]==13) time_buf1[2] = 1;
                Ds1302_Write_Time();
            }
            break;
        case 6: //Day +1
            if(displaynum==2) {
                time_buf1[3]++;
                if(time_buf1[3]==32) time_buf1[3] = 1;
                Ds1302_Write_Time();
            }
            break;
        default: break;
      }
    }
        if(ReadTimeFlag==1) //Display Time or Date
        {
            ReadTimeFlag = 0;
            Ds1302_Read_Time();
            Ds1302_Read_Time_Alarm();
            if(num==1 || num==3 || num==5 || displaynum==0)
            {
                TempData[0] = dofly_DuanMa[time_buf1[4]/10]; //Hour
                TempData[1] = dofly_DuanMa[time_buf1[4]%10];
                TempData[2] = 0x40; //Display : "-"
                TempData[3] = dofly_DuanMa[time_buf1[5]/10]; //Minute
                TempData[4] = dofly_DuanMa[time_buf1[5]%10];
                TempData[5] = 0x40; //Display : "-"
                TempData[6] = dofly_DuanMa[time_buf1[6]/10]; //Second
                TempData[7] = dofly_DuanMa[time_buf1[6]%10];
            }
            else if(num==2 || num==4 || num==6  || displaynum==2)
            {
                TempData[0] = dofly_DuanMa[time_buf1[1]/10]; //Year
                TempData[1] = dofly_DuanMa[time_buf1[1]%10];
                TempData[2] = 0x40; //Display : "-"
                TempData[3] = dofly_DuanMa[time_buf1[2]/10]; //Month
                TempData[4] = dofly_DuanMa[time_buf1[2]%10];
                TempData[5] = 0x40; //Display : "-"
                TempData[6] = dofly_DuanMa[time_buf1[3]/10]; //Day
                TempData[7] = dofly_DuanMa[time_buf1[3]%10];
            }
            else if(num==7 || displaynum==1)
            {
                TempData[0] = dofly_DuanMa[time_buf2[4]/10]; //Hour
                TempData[1] = dofly_DuanMa[time_buf2[4]%10];
                TempData[2] = 0x40; //Display : "-"
                TempData[3] = dofly_DuanMa[time_buf2[5]/10]; //Minute
                TempData[4] = dofly_DuanMa[time_buf2[5]%10];
                TempData[5] = 0x40; //Display : "-"
                TempData[6] = dofly_DuanMa[time_buf2[6]/10]; //Second
                TempData[7] = dofly_DuanMa[time_buf2[6]%10];
            }
            if(time_buf1[5]==0 && time_buf1[6]==0) //Make some noise on the hour
            {
                for(i=0; i<500; i++)
                {
                    DelayUs2x(200);
                    DelayUs2x(200);
                    SPK = !SPK;
                }
                for(i=0; i<500; i++)
                {
                    DelayMs(1);
                    SPK = !SPK;
                }
            }
            if(time_buf1[6]==time_buf2[6] && time_buf1[5]==time_buf2[5] && time_buf1[4]==time_buf2[4]) //Make some noise on the hour/minute
            {
                while(1)
                {
                    for(i=0; i<500; i++)
                    {
                        DelayUs2x(200);
                        DelayUs2x(200);
                        SPK = !SPK;
                    }
                    for(i=0; i<500; i++)
                    {
                        DelayMs(1);
                        SPK = !SPK;
                    }
                    DelayMs(100);
                    num = KeyScan();
                    if(num==7) break; //disable the alaem
                }    
            }
        }
    }
}

void DelayUs2x(unsigned char t) { while(--t); }

void DelayMs(unsigned char t) {
    while(t--) {
        DelayUs2x(245);
        DelayUs2x(245);
    }
}

void Display(unsigned char FirstBit, unsigned char Num) {
    static unsigned char i = 0;

    DataPort = 0;
    LATCH1 = 1;
    LATCH1 = 0;

    DataPort = dofly_WeiMa[i+FirstBit];
    LATCH2 = 1;
    LATCH2 = 0;

    DataPort = TempData[i];
    LATCH1 = 1;
    LATCH1 = 0;

    i++;
    if(i==Num) i = 0;
}

void Init_Timer0(void) {
    TMOD |= 0x01; //Mode 1 : 16 bits timer
    EA = 1; //Open interupt
    ET0 = 1; //Open timer interupt
    TR0 = 1; //Open timer to start
}

void Timer0_isr(void) interrupt 1 {
    static unsigned int num;
    TH0 = (65536-2000)/256; //2ms then interupt
    TL0 = (65536-2000)%256;

    Display(0,8);
    num++;
    if(num==50) //About 100ms
    {
        num = 0;
        ReadTimeFlag = 1; //Read time in DS1302
    }
}

unsigned char KeyScan(void) {
    unsigned char keyvalue;
    unsigned char ReadData;
  
    if(KeyPort!=0xff) {
        DelayMs(100);
        if(KeyPort!=0xff) {
            keyvalue = KeyPort;
            ReadData = keyvalue ^ 0xff;
            Trg = ReadData & (ReadData ^ Cont);
            Cont = ReadData;
            while(KeyPort!=0xff);
            switch(keyvalue) {
                case 0xfe: return 1; break;
                case 0xfd: return 2; break;
                case 0xfb: return 3; break;
                case 0xf7: return 4; break;
                case 0xef: return 5; break;
                case 0xdf: return 6; break;
                case 0xbf: return 7; break;
                case 0x7f: return 8; break;
                default: return 0; break;
            }
        }
    }
    return 0;
}
