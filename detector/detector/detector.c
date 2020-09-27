#include<avr/io.h>
#define F_CPU 16000000UL
//#include<util/delay.h>

void main()
{
DDRA=0;
DDRB=255;

while(1)
	{
if(PINA==0b00000001)
		{
			PORTB=0xff;
		}
else
		PORTB=0;
	}
}
