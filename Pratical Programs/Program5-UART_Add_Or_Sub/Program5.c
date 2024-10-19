#include <reg51.h>
#include "uart.h"

sbit sw = P1^0;
unsigned char current_sw_state;
unsigned char num1, num2;

void ask(){
	Printf("  Enter any number as per your wish: ");
	num1 = ReadBytePC();
	Printf(" Enter another number as per your wish: ");
	num2 = ReadBytePC();
	Printf("");
}

void main(){
	
	SerialInit();
	current_sw_state = sw;
	sw = 0;
	
	ask();
	
	while(1){
	if(sw == 0){
		Printf(" Addition ==> ");
		SendByte2PC(num1+num2);
	}
	else{
		Printf(" Subtraction ==> ");
		SendByte2PC(num1 - num2);
	}
	
	Printf("");
	Printf("Switch 'ON' state ===> Addition ");
	Printf("Switch 'OFF' state ===> Subtraction ");
	Printf("Change the mode of the switch ");
	
	while( sw == current_sw_state);
	current_sw_state = sw;
	ask();
	
 }
	
}
