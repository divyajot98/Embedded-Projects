#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

//unsigned char led[7]={0,0b00001110,0b00001100,0b00001000};

void main()
{DDRB = 0b01111111;
PORTB = 0b00001111;
_delay_ms(500);
	for(int i=1; i<4; i++)
	{	
		for(int j=0; j<4-i; j++)
		{	
			PORTB=(0b00010000<<j); // + ~(0b01111111>>(i-1));
			//PORTB=led[i] + (0b00010000<<j) + ~(0b01111111>>(i-1));
			_delay_ms(500);
		}
	}
}