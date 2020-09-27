#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
//#define Baud_Rate 9600UL
//#define Ubrr_value ((F_CPU/(16*Baud_Rate))-1)
#define lcd PORTD
#include<lib/lcd.h>

/*void USART_init()
{
	//SET Baud Rate
	UBRRL=Ubrr_value;
	UBRRH=(Ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB=(1<<TXEN)|(1<<RXEN);
}*/

void main()
{
	//USART_init();
	lcd_init();
	DDRD=0xff;
	//int z;
	lcd_command(0x81);
	lcd_string(" USART");
	lcd_command(0x86);
	lcd_data("A");
	/*while(1)
	{
		z=UDR;
		lcd_command(0xc3);
		lcd_value(z);
	}*/
}
