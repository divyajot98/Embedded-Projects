#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define gap _delay_ms(5)
#define lcd PORTC
#include <lib/lcd.h>

void main(void)
{
	DDRA=0xf0;
	PORTA=0x0f;
	DDRD=0xff;
	DDRB=0xff;
	DDRC=0xff;
    while(1)
    {
		
		PORTD=0x0e;
		gap;
		if((PINA&0x01)==0)
        {
			PORTB=0x01;
		}
		if((PINA&0x02)==0)
		{
			PORTB=0x02;
		}
		if((PINA&0x04)==0)
		{
			PORTB=0x03;
		}
		if((PINA&0x08)==0)
		{
			PORTB=0x04;
		}
		
		PORTD=0x0d;
		gap;
		if((PINA&0x01)==0)
        {
			PORTB=0x05;
		}
		if((PINA&0x02)==0)
		{
			PORTB=0x06;
		}
		if((PINA&0x04)==0)
		{
			PORTB=0x07;
		}
		if((PINA&0x08)==0)
		{
			PORTB=0x08;
		}
		
		PORTD=0x0b;
		gap;
		if((PINA&0x01)==0)
        {
			PORTB=0x09;
		}
		if((PINA&0x02)==0)
		{
			PORTB=0x0A;
		}
		if((PINA&0x04)==0)
		{
			PORTB=0x0B;
		}
		if((PINA&0x08)==0)
		{
			PORTB=0x0C;
		}
		
		PORTD=0x07;
		gap;
		if((PINA&0x01)==0)
        {
			PORTB=0x0d;
		}
		if((PINA&0x02)==0)
		{
			PORTB=0x0e;
		}
		if((PINA&0x04)==0)
		{
			PORTB=0x0f;
		}
		if((PINA&0x08)==0)
		{
			PORTB=0x00;
		}
    }
}