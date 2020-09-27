#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTB
#include <lib/lcd.h>

void ADC_init()
{
	ADMUX=(1<<REFS0)|(1<<MUX0);
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); // ADEN adc ckt ko enable kr ra h and ADPS0,1,2
}

unsigned int ADC_read(unsigned char ch)

{
	ADMUX|=ch;
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	return ADC;
}

void main()
{
	DDRA=0x00;
	DDRB=0xff;
	DDRD=0xff;
	lcd_init();
	ADC_init();
	unsigned int x = 0;
	lcd_command(0x80);
	lcd_string("ADC Values");
	while (1)
	{
		x=ADC_read(7);
		lcd_command(0x8d);
		lcd_data(x);
		lcd_command(0xc0);
		lcd_string("Temp.");
		lcd_command(0xcc);
		lcd_data((x*4)/10);
		lcd_command(0xce);
		lcd_string("*C");
		_delay_ms(200);
	}
}
