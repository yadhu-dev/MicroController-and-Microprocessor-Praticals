#include <reg51.h>
#include "uart.h"

void main(){
	
	unsigned char num1, num2;
	SerialInit();
	
	Printf("  Enter any number as per your wish: ");
	num1 = ReadBytePC();
	Printf(" Enter another number as per your wish: ");
	num2 = ReadBytePC();
	Printf("");
	Printf("  Quotient ===> ");
	SendByte2PC(num1 / num2);
	Printf("");
	Printf("  Reminder ===> ");
	SendByte2PC(num1 % num2);
	
	while(1);
}
