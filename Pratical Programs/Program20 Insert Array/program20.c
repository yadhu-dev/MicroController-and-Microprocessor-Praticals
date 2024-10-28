#include <reg51.h>
#include "uart_int.h"

unsigned int Arr[5];
unsigned int n,i;

unsigned int Array_Size(){
	Printf("Enter the size of the Array ( MAX : 5 ): ");
	n = ReadIntPC();
	Printf("");
	return n;
}

void Array_Insert(unsigned int n){
	Printf("---------------------");
	Printf("Enter the numbers in Array ");
	Printf("");
	for(i=0;i<n;i++){
		Printf("Enter the number : ");
		Arr[i]= ReadIntPC();
	}
	Printf("---------------------");
	Printf("");
}

void Array_Display(unsigned int n){
	Printf("Numbers in the Array are..");
	Printf("");
	for(i=0;i<n;i++){
		SendInt2PC(Arr[i]);
		Printf("");
	}
}
	
void main(){
	SerialInit();
	n = Array_Size();
	Array_Insert(n);
	Array_Display(n);
	while(1);
}
