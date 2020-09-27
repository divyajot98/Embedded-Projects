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
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
}

void usart_string(char *str)
{
	while(*str)
	{
		usart_transmit(*str++);
	}
}

void main()
{
	USART_init();
	for ( ; ; )
	{
		usart_string("AT+CIPCSGP=1,\"www\"\r\n");	//to connect to prefered APN like www is for Vodafone
		_delay_ms(800);
		//	usart_string("AT+CIPMUX=0\r\n");		//to turn off other connection other than currently running connection 
		//	_delay_ms(5000);
		usart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");//TCP is to turn on the Internet connection, CIPSTART is used to starts the command, api.thingspeak.com is the destination
		_delay_ms(5000);
		usart_string("AT+CIPSEND\r\n");//is used to send the link
		_delay_ms(1000);
		usart_string("GET https://api.thingspeak.com/update?api_key=5NI922SL4EOGTX70&field1=26"); //GET is used to get link  
		usart_string("\r\n");
		_delay_ms(300);
		usart_transmit(0x1A); // is to finalise the commands, its like "over(walkie talky)" command
		_delay_ms(5000);
		usart_string("AT+CIPSHUT\r\n"); // it is the command to end connection like "over and out"
		_delay_ms(5000);
		_delay_ms(5000);
	}
}