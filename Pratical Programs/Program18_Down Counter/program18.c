#include <reg51.h>
#include "sev_segment.h"

#define SEG P3

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i< time; i++){
		for(j=0;j<1275;j++);
	}
}

void down_counter(){
	unsigned char count;
	
	for(count=9; count <= 9; count--){
		SEG = seg_display(count);
		delay(200);
		if(count == 0){
			count = 10;
		}
	}
}

void main(){
	while(1){
		down_counter();
	}
}
