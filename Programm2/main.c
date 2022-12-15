/*
 * Seriell.c
 *
 * Created: 15.12.2022 11:12:38
 * Author : Sebastian Hauschildt
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"

static volatile int8_t value;

ISR (USART_RX_vect)
{
	value = UDR0; // Empfangen
	USART_send(value);
}


int main(void)
{
	USART_init();
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
	//while ( !(UCSR0A & (1 << UDRE0)) )
	//{
		//
	//}
		
    }
}
