#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void main()
{
	DDRA=0x00;
	DDRB=0xff;

	while(1)
	{
		if ((PINA&0x01)==0x01)
			PORTB=0x01;
		else
			PORTB=0;
	}
}