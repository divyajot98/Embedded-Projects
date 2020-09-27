#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<lib/lcd.h>
void main()
{
	DDRA=0;
	DDRB=255;
	DDRC=255;
	DDRD=255;
	lcd_init();
	int z=0, x=0, t=0;
	while(1)
	{
		if(PINA==1)
		{
			while((PINA&0x01)==1);	
			PORTB=1;
			z++;
			lcd_command(0x81);
			lcd_string("IN");
			lcd_command(0xc2);
			lcd_data(z);
			lcd_command(0x85);
			lcd_string("IN B/W");
			t=z-x;
			if(t>=0)
			{
				lcd_command(0xc8);
				lcd_data(t);
				PORTC=t;
			}
		}
		if(PINA==128)
		{
			while((PINA&0x80)==128);                                 
			PORTB=128;
			x++;
			lcd_command(0x8d);
			lcd_string("OUT");
			lcd_command(0xcf);
			lcd_data(x);
			lcd_command(0x85);
			lcd_string("IN B/W");
			t=z-x;
			if(t>=0)
			{
				lcd_command(0xc8);
				lcd_data(t);
			}
		}	
		if (t>0)
			PORTC=0x01;
		else
			PORTC=0;
	}
}
