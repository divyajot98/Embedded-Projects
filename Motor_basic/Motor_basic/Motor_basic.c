#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
#include<lib/lcd.h>
void main()
{
	DDRB=255;
	DDRD=255;
	lcd_init();

	while (1)
	{
		lcd_command(0x84);
		lcd_string("Forward");
		PORTB=0b00000110;	//Forward
		_delay_ms(3000);
		PORTB=0b00000000;	//Stop
		_delay_ms(500);

		lcd_command(0x84);
		lcd_string("Left   ");//spaces are used to clear last values
		PORTB=0b00000010;	//Left
		_delay_ms(3000);
		PORTB=0b00000000; 	//Stop
		_delay_ms(500);

		lcd_command(0x84);
		lcd_string("Right  ");
		PORTB=0b00000100;	//Right
		_delay_ms(3000);
		PORTB=0b00000000;	//Stop
		_delay_ms(500);

		lcd_command(0x84);
		lcd_string("Backward");
		PORTB=0b00001001;	//Backward
		_delay_ms(3000);
		PORTB=0b00000000;	//Stop
		_delay_ms(500);
	}
}