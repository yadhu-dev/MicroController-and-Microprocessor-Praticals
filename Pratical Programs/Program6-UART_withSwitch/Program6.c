#include <reg51.h>
#include "uart.h"

sbit s1 = P1^0; 
sbit s2 = P1^1;
unsigned char current_state_s1;
unsigned char current_state_s2;

void main() {
    unsigned char num1, num2;
    SerialInit();
    
	  Printf("switches( OFF and OFF ) ===> Addition Operation");
	  Printf("switches( OFF and ON ) ===> Subtraction Operation");
	  Printf("switches( ON and OFF ) ===> Multiplication Operation");
	  Printf("switches( ON and ON ) ===> DIvision Operation");
	  Printf("");
    Printf("Enter any number: ");
    num1 = ReadBytePC();
    
    Printf("Enter another number: ");
    num2 = ReadBytePC();
	  Printf("");
    Printf("Change the mode of the switch to get the answer");
    while (1) {
			  
        current_state_s1 = s1; 
        current_state_s2 = s2;
        
        
        while (s1 == current_state_s1 && s2 == current_state_s2);
        
        Printf("");
        if (s1 == 1 && s2 == 1) {
            Printf("Addition: ");
            SendByte2PC(num1 + num2);
        } else if (s1 == 1 && s2 == 0) {
            Printf("Subtraction: ");
            SendByte2PC(num1 - num2);
        } else if (s1 == 0 && s2 == 1) {
            Printf("Multiplication: ");
            SendByte2PC(num1 * num2);
        } else if (s1 == 0 && s2 == 0) {
            Printf("Division: ");
            SendByte2PC(num1 / num2);
        }
				Printf("");
				Printf("");
        Printf("switches( OFF and OFF ) ===> Addition Operation");
				Printf("switches( OFF and ON ) ===> Subtraction Operation");
				Printf("switches( ON and OFF ) ===> Multiplication Operation");
				Printf("switches( ON and ON ) ===> DIvision Operation");
				Printf("");

    }
}
