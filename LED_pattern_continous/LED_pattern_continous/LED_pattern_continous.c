#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>


void main()
{
DDRB = 0b11111111;
for(int i=0; i<8; i++)
	{
	for(int j=0; j<8-i; j++)
		{
     	PORTB= 1<<j;
		PORTB|= ~(255>>i);
		_delay_ms(500);
		}
	}
}