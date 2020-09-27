#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

void main()
{DDRB = 0b11111111;		//PORTB as ouput

//for(int i=0; i<10; i++)
while(1)
{
PORTB = 0b00001111;		//first 4 leds are on

_delay_ms(1000);
PORTB = 0b11110000;		//first 4 leds are off

_delay_ms(1000);
}
}
