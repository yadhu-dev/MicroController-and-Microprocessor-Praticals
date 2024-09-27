# UART Communication Example

## Overview
This repository contains an implementation of UART communication for the 8051 microcontroller. The code demonstrates how to initialize the UART, send bytes, read bytes from the PC, and convert characters.

## Function Definitions and Examples

### 1. `void SerialInit()`
- **Purpose**: Initializes the UART configuration for communication.
- **Example**:
    ```c
    SerialInit(); // Call this function to initialize UART before any communication
    ```


### 2. `void serial(unsigned char x)`
- **Purpose**: Sends a single byte over UART.
- **Parameters**:
  - `unsigned char x`: The byte to be transmitted.
- **Example**:
    ```c
    serial(0x55); // Sends the byte 0x55 over UART
    ```


### 3. `unsigned char Conv2Hex(unsigned char asc)`
- **Purpose**: Converts ASCII characters to their corresponding hexadecimal values.
- **Parameters**:
  - `unsigned char asc`: The ASCII character to be converted.
- **Example**:
    ```c
    unsigned char hexValue = Conv2Hex(0x61); // Converts 'a' (0x61) to 0x0A
    ```


### 4. `void SendByte2PC(unsigned char b)`
- **Purpose**: Sends a byte to the PC in hexadecimal format.
- **Parameters**: 
  - `unsigned char b`: The byte to be sent.
- **Example**:
    ```c
    SendByte2PC(0x3C); // Sends the byte 0x3C to the PC in hexadecimal format
    ```


### 5. `void Printf(unsigned char s[])`
- **Purpose**: Sends a string of characters to the PC.
- **Parameters**: 
  - `unsigned char s[]`: The string to be transmitted.
- **Example**:
    ```c
    unsigned char message[] = "Hello, World!";
    Printf(message); // Sends "Hello, World!" to the PC
    ```


### 6. `unsigned char ReadBytePC()`
- **Purpose**: Reads a byte from the PC and converts it if necessary.
- **Returns**: The converted byte.
- **Example**:
    ```c
    unsigned char receivedByte = ReadBytePC(); // Reads a byte from the PC and stores it in receivedByte
    ```

## Conclusion
This code serves as a fundamental example of UART communication for 8051 microcontrollers. It can be modified and extended for various applications.


## Created By
**Yadhul Mohan**  
B.Sc. in Computer Science and Electronics  
Kristu Jayanti College, Autonomous, Bengaluru, India
