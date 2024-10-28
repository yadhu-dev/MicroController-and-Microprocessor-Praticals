# Microcontroller Array Input and Comparison Program

This program, created for the 8051 microcontroller, demonstrates basic input and output operations using UART (Universal Asynchronous Receiver-Transmitter) for communication between the microcontroller and a computer. The program enables the user to define an array size (up to 5 elements) and input integers into the array. The program then identifies and displays the largest and smallest numbers in the array.

## Output
![Screenshot 2024-10-28 235544](https://github.com/user-attachments/assets/dcb3303f-5a47-4186-bff7-836cd7e14a42)
## Files
- **`main.c`**: The main program file.
- **`uart_int.h`**: Header file providing UART-related functions for initializing serial communication and reading/writing data between the microcontroller and a computer.

## Requirements
- An 8051 microcontroller and a development environment that supports `reg51.h` and UART-based functions.
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
   - Prompts the user to enter the desired array size (maximum size is 5).
   - Returns the array size for use in other functions.

2. **`Array_Insert(unsigned int n)`**:
   - Accepts `n` as the size of the array.
   - Prompts the user to enter `n` integers, which are stored in the global array `Arr`.

3. **`Check_Large(unsigned int n)`**:
   - Iterates through the array to find the largest integer.
   - Returns the largest integer in the array.

4. **`Check_Small(unsigned int n)`**:
   - Iterates through the array to find the smallest integer.
   - Returns the smallest integer in the array.

### Program Workflow
The `main()` function manages the program flow:
1. Initializes the UART communication.
2. Calls `Array_Size()` to determine the array size.
3. Calls `Array_Insert()` to gather user input for the array.
4. Calls `Check_Large()` to find the largest integer and `Check_Small()` to find the smallest integer in the array.
5. Displays the largest and smallest integers to the user.
6. Enters an infinite loop to keep the program running.

---

## Algorithm

1. **Start**:
   - Include the required libraries: `reg51.h` for the 8051 microcontroller and `uart_int.h` for UART functions.

2. **Initialize UART**:
   - Call `SerialInit()` to set up serial communication.

3. **Array Size Input**:
   - Call `Array_Size()`:
     - Prompt the user to enter the array size (up to 5).
     - Store the entered size in variable `n`.

4. **Array Input**:
   - Call `Array_Insert(n)`:
     - Prompt the user to enter `n` integers.
     - Store each integer in the `Arr` array.

5. **Find Largest Number**:
   - Call `Check_Large(n)`:
     - Iterate over the array and compare elements to find the largest integer.
     - Store the largest integer in `Large`.

6. **Find Smallest Number**:
   - Call `Check_Small(n)`:
     - Iterate over the array and compare elements to find the smallest integer.
     - Store the smallest integer in `Small`.

7. **Display Results**:
   - Use `SendInt2PC()` to display both the largest and smallest integers to the user.

8. **Infinite Loop**:
   - Enter an infinite loop (`while(1);`) to keep the program running.

---

## Example Output

- **Prompt**: `Enter the size of the Array (up to 5):`
- **User Enters**: `3`
- **Prompt**: `Enter a number for the Array:`
- **User Inputs**: `10`, `20`, `5`
- **Display**: 
  - `Largest number in the array is 20`
  - `Smallest number in the array is 5`

---

This program serves as a basic example of array manipulation and UART-based communication in embedded C for 8051 microcontrollers. It is useful for learning about data handling, comparisons, and display operations over a serial interface.
