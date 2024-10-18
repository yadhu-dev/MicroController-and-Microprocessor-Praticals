#include <reg51.h>
#include "uart.h"
#include "sev_segment.h"
#define SEG1 P1
#define SEG2 P2

unsigned char a,b, result,c,t,o;

unsigned char collect_ip(){
	Printf("Enter the first number: ");
	a = ReadBytePC();
	Printf("Enter the second number: ");
	b = ReadBytePC();
	if( b == 0 ){
		 Printf("Error: Division by zero");
     return 0;
	}
	 c = a / b;
	return c;
}

unsigned char HN(unsigned char c){
	unsigned char t = (c & 0xf0)>>4;
	return t;
}


unsigned char LN(unsigned char c){
	unsigned char o = c & 0x0f;
	return o;
}

void Led_Display(unsigned char o, unsigned char t){
	SEG2 = seg_display(t);
	SEG1 = seg_display(o);
}
void main(){
	SerialInit();
			result = collect_ip();
			Led_Display(LN(result),HN(result));
		 while(1);
}

	 
