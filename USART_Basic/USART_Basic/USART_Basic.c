#include<avr/io.h>
#define F_CPU 16000000UL
#define Baud_Rate 9600UL
#define Ubrr_value ((F_CPU/(16*Baud_Rate))-1)

void USART_init()
{
	//toSET Baud Rate
	UBRRL=Ubrr_value;
	UBRRH=(Ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB=(1<<TXEN)|(1<<RXEN);
}
unsigned char uart_rec()
{
	while (!(UCSRA&(1<<RXC)));
	return UDR;
}
void main()
{
	DDRB=0xff;		//LED
	USART_init();
	unsigned char x=0;
	while (1)
	{
		x=uart_rec();
		PORTB=x;
	}
}