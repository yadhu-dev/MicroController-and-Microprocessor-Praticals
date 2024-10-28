#include <reg51.h>
#include "uart_int.h"

unsigned int Arr[5];
unsigned int i, n, Large,Small;

unsigned int Array_Size(){
    Printf("Enter the size of the Array (up to 5): ");
    n = ReadIntPC();
	  Printf("------------------------------");
	  Printf("");
    return n;
}

void Array_Insert(unsigned int n){
    for(i = 0; i < n; i++){
        Printf("Enter a number for the Array: ");
        Arr[i] = ReadIntPC();
    }
		Printf("");
}

unsigned int Check_Large(unsigned int n){
    Large = Arr[0]; 
    for(i = 1; i < n; i++){
        if(Arr[i] > Large){
            Large = Arr[i];
        }
    }
    return Large;
}

unsigned int Check_Small(unsigned int n){
	Small = Arr[0];
	for(i=1;i<n;i++){
		if(Small > Arr[i]){
			Small = Arr[i];
		}
	}
	return Small;
}


void main(){
    SerialInit();
    n = Array_Size();
    Array_Insert(n);
    Large = Check_Large(n);
	  Small = Check_Small(n);
	Printf("------------------------------");
	Printf("");
	Printf("Largest number in the array is ");
    SendInt2PC(Large);
	Printf("");
	Printf("Smallest number in the array is ");
	SendInt2PC(Small);
    while(1);
}
