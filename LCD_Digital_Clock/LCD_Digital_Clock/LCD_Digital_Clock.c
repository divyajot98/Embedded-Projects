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
	lcd_string(" DIGITAL CLOCK");
	lcd_command(0xc6);
	lcd_data(':');
	lcd_command(0xc9);
	lcd_data(':');

	for(int i=0; i<3; i++)
	{
		lcd_command(0xc4);
		lcd_data(i+48);

		for(int j=0; j<4; j++)
		{
			lcd_command(0xc5);
			lcd_data(j+48);

			for(int k=0; k<6; k++)
			{
				lcd_command(0xc7);
				lcd_data(k+48);

				for(int l=0; l<10; l++)
				{
					lcd_command(0xc8);
					lcd_data(l+48);

					for(int m=0; m<6; m++)
					{
						lcd_command(0xca);
						lcd_data(m+48);

						for(int n=0; n<10; n++)
						{
							lcd_command(0xcb);
							lcd_data(n+48);
							_delay_ms(450);
						}
					}
				}
			}
		}
	}
}