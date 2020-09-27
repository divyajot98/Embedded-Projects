#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTB
#include<lib/lcd.h>
void main()
{
	DDRB=0xff;
	DDRA=0xee;
	int v=0;
	lcd_init();
	lcd_command(0x83);
	lcd_string(" Visitors");
	while(1)
	{
	if((PINA&0x01)==1)
		{
		while ((PINA&0x02)!=2);
			{
			if((PINA&0x02)==2)
				{
					v++;
					lcd_command(0xc5);
					lcd_data(v);
				}
			}
		}
/*	while((PINA&0x02)==2)
		{
		while ((PINA&0x01)!=1);
			{
			if((PINA&0x01)==1)
				{
				v--;
				lcd_command(0xc5);
				lcd_value(v);
				}
			}
		}*/
	}
}
