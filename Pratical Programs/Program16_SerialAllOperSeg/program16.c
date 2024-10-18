#include <reg51.h>
#include "uart.h"
#include "sev_segment.h"
#define SEG1 P1
#define SEG2 P2

unsigned char ch,result =0,a,b;

void ask(){
	Printf("Enter first number : ");
	a = ReadBytePC();
	Printf("Enter second number : ");
	b = ReadBytePC();
}

unsigned char User_Instructions(){
	Printf("01 for Addition ");
	Printf("02 for Subtraction ");
	Printf("03 for Multiplication ");
	Printf("04 for Division ");
	Printf("Choose any number : ");
	ch = ReadBytePC();
	return ch;
}

unsigned char Operation(unsigned char ch){
	switch(ch){
		case 01:
			ask();
		  result = a+b;
	    break;
		case 02:
			ask();
			result = a-b;
			break;
		case 03:
			ask();
		  result = a*b;
		case 04:
			if(b != 0){
				result = a/b;
			}
			else{
				Printf("Error: Division by zero!");
			}
	}
	return result;
}

unsigned char HN(unsigned char result){
	unsigned char t = (result & 0xf0)>>4;
	return t;
}


unsigned char LN(unsigned char result){
	unsigned char o = result & 0x0f;
	return o;
}

void sev_seg(unsigned char o, unsigned char t){
	SEG2 = seg_display(o);
	SEG1 = seg_display(t);
}

void main(){
	SerialInit();
	 ch = User_Instructions();
	 result = Operation(ch);
	sev_seg(HN(result),LN(result));
	while(1);
}
