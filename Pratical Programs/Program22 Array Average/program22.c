#include <reg51.h>
#include "uart_int.h"

unsigned int Arr[10];
unsigned int n, Total,i,Average;

unsigned int Array_Size(){
	Printf("Enter the size of the Array (Up to 10) : ");
	n = ReadIntPC();
	Printf("--------------------------------------------------------");
	return n;
}

void Array_Insert(unsigned int n){
	Printf("");
	Printf("Enter the numbers into the Array ");
	Printf("--------------------------------------------------------");
	for(i=0;i<n;i++){
		Printf("Enter the number : ");
		Arr[i] = ReadIntPC();
	}
	Printf("--------------------------------------------------------");
	Printf("");
}

unsigned int Array_Sum(unsigned int n){
	Total = 0;
	for(i=0;i<n;i++){
		Total += Arr[i];
	}
	return Total;
}

void Avg(unsigned int n, unsigned int Total){
	Average = Total/n;
	Printf("The Average of your Array is ");
	SendInt2PC(Average);
}

void main(){
	SerialInit();
	n = Array_Size();
	Array_Insert(n);
	Total = Array_Sum(n);
	Avg(n,Total);
	while(1);
}
