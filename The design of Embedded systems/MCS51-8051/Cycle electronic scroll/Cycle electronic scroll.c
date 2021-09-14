#include <reg52.h>

#define BUS P0

unsigned char code font[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char code digit[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};

sbit fontcs = P2^0;
sbit digitcs = P2^1;

void delay(unsigned int d)
{
	unsigned int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<d;j++)
			;
}

void put_data(unsigned char i,unsigned char j)
{
	BUS = 0xff - font[j];
	fontcs = 1;
	fontcs = 0;

	BUS = digit[i];
	digitcs = 1;
	digitcs = 0;
}

void main()
{
	while(1)
	{
		put_data(0,0);
		delay(1000);
		put_data(1,0);
		delay(1000);
		put_data(2,8);
		delay(1000);
		put_data(3,8);
		delay(1000);
		put_data(4,9);
		delay(1000);
		put_data(5,2);
		delay(1000);
		put_data(6,0);
		delay(1000);
		put_data(7,6);
		delay(1000);
	}
}
