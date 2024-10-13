#include <reg51.h>

sbit sw1 = P3^0;
sbit sw2 = P3^1;
	
	
void Add(){
	P2 =P0+ P1;
}

void Sub(){
	P2 = P0-P1;
}

void Mul(){
	P2 = P0*P1;
}

void Div(){
	P2 = P0/P1;

}



void main(){
	sw1 = 0;
	sw2 = 0;
	while(1){
		
		if(sw1 == 0 && sw2 == 0 ){
			
			Add();
		}
		
		else if(sw1 == 0 && sw2 == 1){
			Sub();
		}
		else if(sw1 == 1 && sw2 == 0){
			Mul();
		}
		else if(sw1 == 1 && sw2 == 1){
			Div();		
   }
 }
}
