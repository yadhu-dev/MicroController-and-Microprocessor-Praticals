#ifndef UART_H
#define UART_H

// Function Prototypes
void SerialInit(void);
void serial(unsigned char x);
unsigned char Conv2Hex(unsigned char asc);
void SendByte2PC(unsigned char b);
void Printf(unsigned char s[]);
unsigned char ReadBytePC(void);
