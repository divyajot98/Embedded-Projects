#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<lib/lcd.h>

void main()
{
	DDRD=255;
	lcd_init();

	lcd_command(0x80);
	lcd_string("Value");

	lcd_command(0x8b);
	lcd_string("ASCII");

	char i=0;

	for (int j=0; j<5; j++)
	{
		lcd_command(0xcc);
		lcd_data(j+48);
		for (int k=0; k<10; k++)
		{
			lcd_command(0xcd);
			lcd_data(k+48);
			for (int l=0; l<10; l++)
			{
				lcd_command(0xce);
				lcd_data(l+48);
				lcd_command(0xc1);
				lcd_data(i);
				i++;
				_delay_ms(250);
			}
		}
	}
}