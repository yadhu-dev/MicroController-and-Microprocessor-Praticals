# Microcontroller Array Input and Display Program

This program, designed for the 8051 microcontroller, demonstrates basic input and output operations using UART (Universal Asynchronous Receiver-Transmitter) for communication between the microcontroller and a computer. The program allows the user to enter an array size (up to 5 elements) and then input integers into the array. After all elements are entered, the program displays each number back to the user.

## OUTPUT
![Screenshot 2024-10-28 234822](https://github.com/user-attachments/assets/22b64b89-c0b0-4f9a-ac9b-991a032fa2ba)

## Files
- **`main.c`**: The main program file.
- **`uart_int.h`**: Header file providing UART-related functions for initializing serial communication and reading/writing data between the microcontroller and a computer.

## Requirements
- Keil Ide with  (`reg51.h` and UART-based functions) and Proteus Software.
- **`uart_int.h`** header file, which provides UART functions necessary for serial communication.

## Function Descriptions

### UART Functions from `uart_int.h`
The `uart_int.h` header file is used to facilitate communication between the 8051 microcontroller and the computer through UART. It contains the following functions:
- `SerialInit()`: Initializes the serial communication.
- `Printf(char *str)`: Sends a string to the computer via UART.
- `ReadIntPC()`: Reads an integer input from the user over UART.
- `SendInt2PC(int num)`: Sends an integer from the microcontroller to the computer via UART.

### Program Functions
1. **`Array_Size()`**: 
   - Prompts the user to enter the desired array size.
   - The maximum allowable array size is 5.
   - Returns the array size to be used for the next functions.

2. **`Array_Insert(unsigned int n)`**: 
   - Accepts `n` as the size of the array.
   - Prompts the user to enter `n` integers, which are stored in the global array `Arr`.

3. **`Array_Display(unsigned int n)`**: 
   - Accepts `n` as the size of the array.
   - Displays each element of the array `Arr` by sending it to the computer over UART.

### Program Workflow
The `main()` function orchestrates the flow:
1. Initializes the UART communication.
2. Calls `Array_Size()` to determine the array size.
3. Calls `Array_Insert()` to allow user input for the array.
4. Calls `Array_Display()` to display each integer back to the user.
5. Enters an infinite loop to keep the program running.

---

## Algorithm

1. **Start**:
   - Include the required libraries, specifically `reg51.h` for the 8051 microcontroller and `uart_int.h` for UART functions.

2. **Initialize UART**:
   - Call `SerialInit()` to set up serial communication with the computer.

3. **Array Size Input**:
   - Call `Array_Size()`:
     - Prompt the user to enter the size of the array (up to 5).
     - Store the entered size in variable `n`.

4. **Array Input**:
   - Call `Array_Insert(n)`:
     - Prompt the user to enter `n` integers.
     - Store each integer in the `Arr` array.

5. **Array Display**:
   - Call `Array_Display(n)`:
     - Iterate over the array `Arr` and send each element back to the computer for display.

6. **Infinite Loop**:
   - Enter an infinite loop (`while(1);`) to keep the program running.

---

## Example Output

- **Prompt**: `Enter the size of the Array (MAX: 5):`
- **User Enters**: `3`
- **Prompt**: `Enter the numbers in Array`
- **User Inputs**: `10`, `20`, `30`
- **Display**: `Numbers in the Array are: 10, 20, 30`

---

This program is a simple demonstration of handling arrays and UART-based communication in embedded C for 8051 microcontrollers. It provides a foundation for more complex data handling and display tasks through serial interfaces.
