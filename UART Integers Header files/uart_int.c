#include <reg51.h> 
#include "uart_int.h"

// TH1 = 226 for 9600 baud rate with 11.0592 MHz crystal
#define TH1_VALUE 0xFD      


void SerialInit()
{
    TMOD = 0x20;     // Timer 1, Mode 2 (8-bit auto-reload)
    TH1 = TH1_VALUE; // Set timer reload value for baud rate 9600
    SCON = 0x50;     // Configure UART in mode 1 (8-bit UART)
    TR1 = 1;         // Start Timer 1
    TI = 0;          // Indicate transmit ready
    RI = 0;
}
void serial(unsigned char x)
{
    SBUF = x; // Place value in Buffer
    while (TI == 0)
    {
    } // Wait until Transmitted
    TI = 0;
}

void Printf(unsigned char s[])
{
    char i;
    i = 0;
    serial(0x0d);
    while (1)
    {
        if (s[i] == '\0')
            break;
        serial(s[i]);
        i++;
    }
}

unsigned int ReadIntPC(){
	unsigned int RcvInt = 0;
	unsigned char input;
	
	while(1){
		while(RI == 0);
		input = SBUF;
		RI = 0;
		if(input < '0' || input > '9'){
			break;
		}
		RcvInt = RcvInt*10+(input - '0');
		serial(input);
	}
	return RcvInt;
}

void SendInt2PC(unsigned int value){
	unsigned int divisor = 10000;
	unsigned char digit;
	unsigned char leading_zero =1;
	
	if(value == 0){
		serial('0');
		return;
	}
	
	while(divisor > 0){
		digit = (value/divisor)%10;
		
		if(digit == 0 && leading_zero && divisor > 1){
			divisor /= 10;
			continue;
		}
		serial(0x30 + digit);
		divisor /= 10;
	}
}
