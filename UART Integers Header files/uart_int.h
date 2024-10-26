#ifndef UART_INT_H
#define UART_INT_H

// Function Prototypes
void SerialInit(void);
void serial(unsigned char x);
void Printf(unsigned char s[]);
unsigned int ReadIntPC(void);
void SendInt2PC(unsigned int value);
