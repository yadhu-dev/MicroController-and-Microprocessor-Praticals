#include <reg51.h>
#include "uart_int.h"

unsigned int Arr[10],Even[10],Odd[10];
unsigned int n, i,Total,even_index=0,odd_index;

unsigned int Array_Size(unsigned int n){
	Printf("Enter the size of the array : ");
	n = ReadIntPC();
	Printf("---------------------------------------------------");
	Printf("");
	return n;
}

void Array_Insert(unsigned int n){
	Printf("Enter the numbers inside the array ");
	Printf("---------------------------------------------------");
	for(i=0;i<n;i++){
		Printf("Enter the number : ");
		Arr[i] = ReadIntPC();
	}
}

void Array_Display(unsigned int n){
	Printf("---------------------------------------------------");
	Printf("");
	Printf("These is your your Array numbers : ");
	for(i=0;i<n;i++){
		Printf("");
		SendInt2PC(Arr[i]);
		Printf("");
	}
}

void FindEven(unsigned int n){
	for(i=0;i<n;i++){
		if(Arr[i]%2 == 0){
			Even[even_index++] = Arr[i];
		}
	}
	Printf("---------------------------------------------------");
	Printf("");
	Printf("Even numbers of your Array is ");
	for(i=0;i<even_index;i++){
		Printf("");
		SendInt2PC(Even[i]);
		Printf("");
	}
}

void FindOdd(unsigned int n){
	for(i=0;i<n;i++){
		if(Arr[i]%2 != 0){
			Odd[odd_index++] = Arr[i];
		}
	}
	Printf("---------------------------------------------------");
	Printf("");
	Printf("Odd numbers of your Array is ");
	for(i=0;i<odd_index;i++){
		Printf("");
		SendInt2PC(Odd[i]);
		Printf("");
	}
}

unsigned TotalEven(unsigned int n){
	Total=0;
	for(i=0;i<n;i++){
		Total += Even[i];
	}
	return Total;
}

unsigned TotalOdd(unsigned int n){
	Total=0;
	for(i=0;i<n;i++){
		Total += Odd[i];
	}
	return Total;
}

void main(){
	SerialInit();
	n = Array_Size();
	Array_Insert(n);
	Array_Display(n);
	FindEven(n);
	Total = TotalEven(n);
	Printf("---------------------------------------------------");
	Printf("Total Even numbers are : ");
	SendInt2PC(Total);
	Printf("---------------------------------------------------");
	Printf("");
	FindOdd(n);
	Total = TotalOdd(n);
	Printf("---------------------------------------------------");
	Printf("Total Odd numbers are : ");
	SendInt2PC(Total);
	Printf("---------------------------------------------------");
	Printf("");
	while(1);
}
