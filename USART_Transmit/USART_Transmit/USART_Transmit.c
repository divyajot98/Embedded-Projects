#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define Baud_Rate 9600UL
#define Ubrr_value ((F_CPU/(16*Baud_Rate))-1)

void USART_init()
{
	//SET Baud Rate
	UBRRL=Ubrr_value;
	UBRRH=(Ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	UCSRB=(1<<TXEN)|(1<<RXEN);
}

void usart_transmit(unsigned char data)
{
	while((!UCSRA&(1<<UDRE)));
	UDR=data;
}

void main()
{
	DDRC=0x00;
	USART_init();
	int x=0;
	while(1)
	{
		if ((PINC&0x01)==0x01)
		{
			while(PINC==0x01);
			x++;
			usart_transmit(x);
			_delay_ms(500);
		}
	}
}
