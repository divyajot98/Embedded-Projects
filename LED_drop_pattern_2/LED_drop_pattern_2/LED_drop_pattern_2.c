#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void main()
{
	DDRB = 0b11111111;
	for(int i=0; i<8; i++)
	{
		PORTB|=(1<<i);
		_delay_ms(500);
	}

}