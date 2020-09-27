#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
void main()
{
	DDRA=0;
	DDRB=255;
	while(1)
	{
		if(PINA==1)
		{
			while(PINA==1);	
			PORTB=~PORTB;
		}
	}
}