//here you can give input through swicthes and press the assign button and you can see the multiplication result of your input

#include <reg51.h>
#include "sev_segment.h"
sbit Assign_btn = P0^0;
sbit Reset_btn = P0^7;

unsigned char a, o, t, c=0;
unsigned char ones, tens;

void delay(unsigned char time){
	unsigned char i,j;
	for(i=0;i<=time;i++){
		for(j=0;j<=124;j++);
	}
}

void Reset(){
	if(Reset_btn == 1){
		c =0;
		while(Reset_btn == 1);
	}
	delay(50);
}
void Assign(){
	if(Assign_btn == 1){
		delay(50);
		if(Assign_btn ==1){
			
			if(c == 0){
				c+=a;
			}
			else{
				c*=a;
			}
			a = 0;
			while(Assign_btn ==1);
		}
		delay(50);
	}
}
unsigned char collect_ip(){
	a = P1;
	Assign();
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
	P2 = seg_display(o);
	P3 = seg_display(t);
}
	

void main(){
	Assign_btn =0;
	Reset_btn =0;
	while(1){
		collect_ip();
	ones = LN(c);
	tens = HN(c);
	
	Led_Display(ones, tens);
	a = 0;
	if(Reset_btn == 1){
		delay(50);
		Reset();
	 }
	}
}
	
