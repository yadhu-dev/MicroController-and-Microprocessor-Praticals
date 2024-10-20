#include <reg51.h>
#define sw1 P0
#define sw2 P1
#define led P2
	
void main(){
	
	while(1){
		led = sw1 / sw2;
}
	}
