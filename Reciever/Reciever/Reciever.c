#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define Baud_Rate 9600UL
#define Ubrr_value ((F_CPU/(16*Baud_Rate))-1)
#define lcd PORTC
#include<lib/lcd.h>

void USART_init()
{
	//SET Baud Rate
	UBRRL=Ubrr_value;
	UBRRH=(Ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB=(1<<TXEN)|(1<<RXEN);
}

void uart_send(unsigned char data)
{
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}
unsigned char uart_rec()
{
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}
void main()
{
	DDRC=0xff;
	USART_init();
	lcd_init();

	int z=0;
	lcd_command(0x81);
	lcd_string(" USART");
	while(1)
	{
		z=uart_rec();
		lcd_command(0xc6);
		lcd_data(z);
	}
}
