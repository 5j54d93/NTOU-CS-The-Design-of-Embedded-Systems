#ifndef __DS1302_H__
#define __DS1302_H__

#include <reg52.h>
#include<intrins.h>

sbit SCK=P1^4;		
sbit SDA=P1^5;		
sbit RST=P1^6;

#define RST_CLR	RST=0
#define RST_SET	RST=1

#define IO_CLR	SDA=0
#define IO_SET	SDA=1
#define IO_R	SDA

#define SCK_CLR	SCK=0
#define SCK_SET	SCK=1

#define ds1302_sec_add			0x80
#define ds1302_min_add			0x82
#define ds1302_hr_add			0x84
#define ds1302_date_add			0x86
#define ds1302_month_add		0x88
#define ds1302_day_add			0x8a
#define ds1302_year_add			0x8c
#define ds1302_control_add		0x8e
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

#define ds1302_sec_add1			0xc0
#define ds1302_min_add1			0xc2
#define ds1302_hr_add1			0xc4
#define ds1302_date_add1		0xc6
#define ds1302_month_add1		0xc8
#define ds1302_day_add1			0xca
#define ds1302_year_add1		0xcc
#define ds1302_control_add1		0xce
#define ds1302_charger_add1		0xd0 					 
#define ds1302_clkburst_add1	0xfe

extern unsigned char time_buf2[8];
extern unsigned char time_buf1[8];
extern unsigned char time_buf[8];

//extern unsigned char time_buf21[8];

void Ds1302_Write_Byte(unsigned char addr, unsigned char d);

unsigned char Ds1302_Read_Byte(unsigned char addr);

void Ds1302_Write_Time(void);

void Ds1302_Read_Time(void);

void Ds1302_Init(void);

void Ds1302_Write_Time_Alarm(void);

void Ds1302_Read_Time_Alarm(void);

#endif
