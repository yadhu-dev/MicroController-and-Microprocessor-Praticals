#include <reg51.h>
#include "uart.h"

unsigned char Vowels[10] = {'a', 'e','i','o','u','A','E','I','O','U'};
unsigned char Arr[10];
unsigned int count,i,n,j;


unsigned int ReadIntPC(){
	unsigned int RcvInt = 0;
	unsigned char input;
	
	while(1){
		while(RI == 0);
		input = SBUF;
		RI = 0;
		if(input < '0' || input > '9'){
			break;
		}
		RcvInt = RcvInt*10+(input - '0');
		serial(input);
	}
	return RcvInt;
}

void SendInt2PC(unsigned int value){
	unsigned int divisor = 10000;
	unsigned char digit;
	unsigned char leading_zero =1;
	
	if(value == 0){
		serial('0');
		return;
	}
	
	while(divisor > 0){
		digit = (value/divisor)%10;
		
		if(digit == 0 && leading_zero && divisor > 1){
			divisor /= 10;
			continue;
		}
		serial(0x30 + digit);
		divisor /= 10;
	}
}


unsigned int Array_Size(){
	Printf("Enter the Size of the array : ");
	n = ReadIntPC();
	Printf("");
	return n;
}


void Array_Insert(unsigned int n){
	unsigned char input;
	Printf("--------------------------------------------");
	for(i=0;i<n;i++){
		Printf("Enter a character ( a-z || A-Z ) : ");
		while(1){
			while(RI == 0 );
			input = SBUF;
			RI = 0;
			
			if(( input >= 'a' && input <= 'z' )|| ( input >= 'A' && input <= 'Z' )){
				Arr[i] = input;
				serial(input);
				break;
			}
			else{
				Printf("Invalid input... Please enter a character ( a-z || A-Z )");
			}
		}
	}
	Printf("--------------------------------------------");
	Printf("");
}
	

unsigned int Count_Vowels(unsigned char Array_name[],unsigned int n){
	count = 0;
	for(i=0;i<n;i++){
		for(j=0;j<10;j++){
			if(Array_name[i] == Vowels[j]){
				count++;
				break;
			}
		}
	}
	return count;
}

void main(){
	SerialInit();
	n = Array_Size();
	Array_Insert(n);
	count = Count_Vowels(Arr,n);
	Printf("Total Numbers of Vowels in your array is : ");
	SendInt2PC(count);
	while(1);
}
