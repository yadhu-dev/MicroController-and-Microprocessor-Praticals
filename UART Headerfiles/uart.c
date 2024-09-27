#include <reg51.h> 
#include "uart.h"

// TH1 = 226 for 9600 baud rate with 11.0592 MHz crystal
#define TH1_VALUE 0xFD      


void SerialInit()
{
    TMOD = 0x20;     // Timer 1, Mode 2 (8-bit auto-reload)
    TH1 = TH1_VALUE; // Set timer reload value for baud rate 9600
    SCON = 0x50;     // Configure UART in mode 1 (8-bit UART)
    TR1 = 1;         // Start Timer 1
    TI = 0;          // Indicate transmit ready
    RI = 0;
}
void serial(unsigned char x)
{
    SBUF = x; // Place value in Buffer
    while (TI == 0)
    {
    } // Wait until Transmitted
    TI = 0;
}
unsigned char Conv2Hex(unsigned char asc)
{
    switch (asc)
    {
    case 0x61:
    case 0x41:
        return (0x0a);
        break;

    case 0x62:
    case 0x42:
        return (0x0b);
        break;

    case 0x63:
    case 0x43:
        return (0x0c);
        break;

    case 0x64:
    case 0x44:
        return (0x0d);
        break;

    case 0x65:
    case 0x45:
        return (0x0e);
        break;

    case 0x66:
    case 0x46:
        return (0x0f);
        break;
    }
}
void SendByte2PC(unsigned char b)
{
    if (((b & 0xf0) >> 4) > 9)
        serial(0x37 + ((b & 0xf0) >> 4));
    else
        serial(0x30 + ((b & 0xf0) >> 4));

    if (((b & 0x0f)) > 9)
        serial(0x37 + ((b & 0x0f)));
    else
        serial(0x30 + (b & 0x0f));
}
void Printf(unsigned char s[])
{
    char i;
    i = 0;
    serial(0x0d);
    while (1)
    {
        if (s[i] == '\0')
            break;
        serial(s[i]);
        i++;
    }
}
unsigned char ReadBytePC()
{
    unsigned char RcvByte;
    RcvByte = 0x00;
    while (RI == 0)
        ;
    if (SBUF > 0x40)
        RcvByte = (Conv2Hex(SBUF) << 4);
    else
        RcvByte = ((0x0f & SBUF) << 4);
    RI = 0;
    serial(SBUF);
    while (RI == 0)
        ;
    if (SBUF > 0x40)
        RcvByte = RcvByte + Conv2Hex(SBUF);
    else
        RcvByte = RcvByte + (0x0f & SBUF);

    RI = 0;
    serial(SBUF);
    // byte2PC(RcvByte);
    return (RcvByte);
}
