/*
 * Senden.c
 *
 * Created: 15.12.2022 11:53:09
 *  Author: a830494
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD -1

void USART_send(int8_t value) {
	UDR0 = value;
}

void USART_init() {
	// Baudrate setzen
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
	
	
	// RX Datenempfang aktivieren TX Datensenden aktivieren (DDR nicht notwendig)
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	
	
	// Protokoll
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Set frame: 8data, 1 stp
	
	
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
}