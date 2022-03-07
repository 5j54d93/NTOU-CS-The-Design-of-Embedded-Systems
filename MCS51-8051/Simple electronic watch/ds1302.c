#include "ds1302.h"
unsigned char time_buf2[8] = {20,0,0,0,18,51,00,6};
unsigned char time_buf1[8] = {20,9,3,13,18,51,00,6};
unsigned char time_buf[8];

void Ds1302_Write_Byte(unsigned char addr, unsigned char d)
{
    unsigned char i;
    RST_SET;    
    
    addr = addr & 0xFE;
    for(i = 0; i < 8; i ++)
    {
        if(addr & 0x01) IO_SET;
        else IO_CLR;

        SCK_SET;
        SCK_CLR;
        addr = addr >> 1;
    }
    
    for(i = 0; i < 8; i ++)
    {
        if(d & 0x01) IO_SET;
        else IO_CLR;

        SCK_SET;
        SCK_CLR;
        d = d >> 1;
    }
    RST_CLR;
}

unsigned char Ds1302_Read_Byte(unsigned char addr) 
{
    unsigned char i;
    unsigned char temp;
    RST_SET;    

    addr = addr | 0x01;
    for(i = 0; i < 8; i ++)
    {
        if(addr & 0x01) IO_SET;
        else IO_CLR;

        SCK_SET;
        SCK_CLR;
        addr = addr >> 1;
    }
    
    for(i = 0; i < 8; i ++)
    {
        temp = temp >> 1;
        if(IO_R) temp |= 0x80;
        else temp &= 0x7F;

        SCK_SET;
        SCK_CLR;
    }
    
    RST_CLR;
    return temp;
}

void Ds1302_Write_Time_Alarm(void) 
{
    unsigned char i,tmp;
    for(i=0;i<8;i++)
    {//BCD
        tmp=time_buf2[i]/10;
        time_buf[i]=time_buf2[i]%10;
        time_buf[i]=time_buf[i]+tmp*16;
    }
    Ds1302_Write_Byte(ds1302_control_add,0x00);
    Ds1302_Write_Byte(ds1302_year_add1,time_buf[1]);
    Ds1302_Write_Byte(ds1302_month_add1,time_buf[2]);
    Ds1302_Write_Byte(ds1302_date_add1,time_buf[3]);
//  Ds1302_Write_Byte(ds1302_day_add1,time_buf[7]);
    Ds1302_Write_Byte(ds1302_hr_add1,time_buf[4]);
    Ds1302_Write_Byte(ds1302_min_add1,time_buf[5]);
    Ds1302_Write_Byte(ds1302_sec_add1,time_buf[6]);
    Ds1302_Write_Byte(ds1302_day_add1,time_buf[7]);
    Ds1302_Write_Byte(ds1302_control_add,0x80);
}

void Ds1302_Read_Time_Alarm(void)  
{ 
    unsigned char i,tmp;
    time_buf[1]=Ds1302_Read_Byte(ds1302_year_add1);
    time_buf[2]=Ds1302_Read_Byte(ds1302_month_add1);
    time_buf[3]=Ds1302_Read_Byte(ds1302_date_add1);
    time_buf[4]=Ds1302_Read_Byte(ds1302_hr_add1);
    time_buf[5]=Ds1302_Read_Byte(ds1302_min_add1);
    time_buf[6]=(Ds1302_Read_Byte(ds1302_sec_add1))&0x7F;
    time_buf[7]=Ds1302_Read_Byte(ds1302_day_add1);

    for(i=0;i<8;i++)
    {//BCD
        tmp=time_buf[i]/16;
        time_buf2[i]=time_buf[i]%16;
        time_buf2[i]=time_buf2[i]+tmp*10;
    }
}

void Ds1302_Write_Time(void) 
{
    unsigned char i,tmp;
    for(i=0;i<8;i++)
    {//BCD
        tmp=time_buf1[i]/10;
        time_buf[i]=time_buf1[i]%10;
        time_buf[i]=time_buf[i]+tmp*16;
    }
    Ds1302_Write_Byte(ds1302_control_add,0x00);
    Ds1302_Write_Byte(ds1302_sec_add,0x80);
    //Ds1302_Write_Byte(ds1302_charger_add,0xa9);
    Ds1302_Write_Byte(ds1302_year_add,time_buf[1]);
    Ds1302_Write_Byte(ds1302_month_add,time_buf[2]);
    Ds1302_Write_Byte(ds1302_date_add,time_buf[3]);
//  Ds1302_Write_Byte(ds1302_day_add,time_buf[7]);
    Ds1302_Write_Byte(ds1302_hr_add,time_buf[4]);
    Ds1302_Write_Byte(ds1302_min_add,time_buf[5]);
    Ds1302_Write_Byte(ds1302_sec_add,time_buf[6]);
    Ds1302_Write_Byte(ds1302_day_add,time_buf[7]);
    Ds1302_Write_Byte(ds1302_control_add,0x80);
}

void Ds1302_Read_Time(void)  
{ 
    unsigned char i,tmp;
    time_buf[1]=Ds1302_Read_Byte(ds1302_year_add);
    time_buf[2]=Ds1302_Read_Byte(ds1302_month_add);
    time_buf[3]=Ds1302_Read_Byte(ds1302_date_add);
    time_buf[4]=Ds1302_Read_Byte(ds1302_hr_add);
    time_buf[5]=Ds1302_Read_Byte(ds1302_min_add);
    time_buf[6]=(Ds1302_Read_Byte(ds1302_sec_add))&0x7F;
    time_buf[7]=Ds1302_Read_Byte(ds1302_day_add);

    for(i=0;i<8;i++)
    {//BCD
        tmp=time_buf[i]/16;
        time_buf1[i]=time_buf[i]%16;
        time_buf1[i]=time_buf1[i]+tmp*10;
    }
}

void Ds1302_Init(void)
{
    RST_CLR;
    SCK_CLR;
    Ds1302_Write_Byte(ds1302_sec_add,0x00);              
}
