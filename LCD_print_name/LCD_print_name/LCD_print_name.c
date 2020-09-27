#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<lib/lcd.h>

void main()
{
	DDRD=255;
	lcd_init();
	lcd_command(0x83);
	lcd_string("Moving display");
	_delay_ms(300);
	while (1)
	{
		lcd_command(0x18);	//moves entire display right to left
		_delay_ms(300);
	}

}