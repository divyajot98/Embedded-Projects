#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

unsigned char dig[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};

void main()
{
	DDRB=0b11111111;
	DDRA=0b11111111;
	for (int i=0; i<10; i++)
	{	
		PORTB = dig[i];
		for (int j=0; j<10; j++)
		{
			PORTA = dig[j];
			_delay_ms(300);
		}
	}
}