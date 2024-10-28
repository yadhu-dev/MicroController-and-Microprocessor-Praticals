# Microcontroller Array Sum and Average Program

This program, designed for the 8051 microcontroller, demonstrates basic input and output operations using UART (Universal Asynchronous Receiver-Transmitter) to communicate with a computer. The program allows the user to input an array size (up to 10 elements) and then enter integers into the array. It calculates the sum and average of the array elements and displays the average back to the user.

## OUTPUT

![Screenshot 2024-10-29 002648](https://github.com/user-attachments/assets/1f84f210-f593-4559-9785-f824e5163695)
## Files
- **`main.c`**: The main program file.
- **`uart_int.h`**: Header file providing UART-related functions for initializing serial communication and reading/writing data between the microcontroller and a computer.

## Requirements
- Keil u vision IDE with ( `reg51.h` and UART-based functions) and Proteus Software.
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
   - Prompts the user to enter the desired array size (maximum size is 10).
   - Returns the array size for use in other functions.

2. **`Array_Insert(unsigned int n)`**:
   - Accepts `n` as the size of the array.
   - Prompts the user to enter `n` integers, which are stored in the global array `Arr`.

3. **`Array_Sum(unsigned int n)`**:
   - Iterates through the array to calculate the sum of all elements.
   - Returns the total sum of the array.

4. **`Avg(unsigned int n, unsigned int Total)`**:
   - Calculates the average by dividing the `Total` by `n`.
   - Displays the average to the user.

### Program Workflow
The `main()` function organizes the flow as follows:
1. Initializes the UART communication.
2. Calls `Array_Size()` to determine the array size.
3. Calls `Array_Insert()` to gather user input for the array.
4. Calls `Array_Sum()` to calculate the sum of the array elements.
5. Calls `Avg()` to calculate and display the average.
6. Enters an infinite loop to keep the program running.

---

## Algorithm

1. **Start**:
   - Include the required libraries, specifically `reg51.h` for the 8051 microcontroller and `uart_int.h` for UART functions.

2. **Initialize UART**:
   - Call `SerialInit()` to set up serial communication.

3. **Array Size Input**:
   - Call `Array_Size()`:
     - Prompt the user to enter the array size (up to 10).
     - Store the entered size in variable `n`.

4. **Array Input**:
   - Call `Array_Insert(n)`:
     - Prompt the user to enter `n` integers.
     - Store each integer in the `Arr` array.

5. **Sum Calculation**:
   - Call `Array_Sum(n)`:
     - Iterate over the array `Arr` and add each element to `Total`.
     - Store the sum in `Total`.

6. **Average Calculation and Display**:
   - Call `Avg(n, Total)`:
     - Calculate the average by dividing `Total` by `n`.
     - Display the average using `SendInt2PC()`.

7. **Infinite Loop**:
   - Enter an infinite loop (`while(1);`) to keep the program running.

---

## Example Output

- **Prompt**: `Enter the size of the Array (Up to 10):`
- **User Enters**: `4`
- **Prompt**: `Enter the numbers into the Array`
- **User Inputs**: `10`, `20`, `30`, `40`
- **Display**:
  - `The Average of your Array is 25`

---

This program provides a basic example of array manipulation, summation, and average calculation in embedded C for 8051 microcontrollers, with output displayed over a serial interface.
