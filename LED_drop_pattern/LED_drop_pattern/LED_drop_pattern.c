#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>

//unsigned char led[8]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};

void main()
{DDRB = 0b11111111;		//PORTB as ouput

for(int i=0; i<8; i++)

{ PORTB = 0b00000001<<i;
//PORTB = led[i];
_delay_ms(500);
}


/* while(1)
{
PORTB = 0b00000001;		

_delay_ms(500);
PORTB = 0b00000010;		

_delay_ms(500);
PORTB = 0b00000100;		

_delay_ms(500);

PORTB = 0b00001000;		

_delay_ms(500);
PORTB = 0b00010000;		

_delay_ms(500);

PORTB = 0b00100000;		

_delay_ms(500);
PORTB = 0b01000000;		

_delay_ms(500);
PORTB = 0b10000000;		
_delay_ms(500);  */

}