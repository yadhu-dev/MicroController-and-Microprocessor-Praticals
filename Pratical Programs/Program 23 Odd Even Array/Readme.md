# Microcontroller Program for Array Manipulation and Sum of Even/Odd Numbers

This program for the 8051 microcontroller accepts an array of integers, separates the even and odd numbers, and calculates the sum of each. The program communicates with a computer over UART, displaying results and receiving user input for the array.

## Output
o/p1
![Screenshot 2024-10-29 083645](https://github.com/user-attachments/assets/96194daf-9193-4054-a66d-70fd85dc11a8)
o/p2
![Screenshot 2024-10-29 083740](https://github.com/user-attachments/assets/593754b0-57c3-47f0-8a90-b9fdfcd2efbe)
## Files
- **`main.c`**: The main program file.
- **`uart_int.h`**: Header file providing UART-related functions for communication with the computer.

## Requirements
- 8051 microcontroller and development environment compatible with `reg51.h` and UART.
- **`uart_int.h`** file with functions to handle UART communication.

## Program Description

### Functions from `uart_int.h`
- **`SerialInit()`**: Initializes UART communication.
- **`Printf(char *str)`**: Sends strings to the computer.
- **`ReadIntPC()`**: Reads an integer from the computer.
- **`SendInt2PC(int num)`**: Sends an integer from the microcontroller to the computer.

### Main Functions
1. **`Array_Size()`**:
   - Prompts the user for the array size.
   - Returns the array size, `n`.

2. **`Array_Insert()`**:
   - Accepts integers from the user and populates the global array `Arr`.

3. **`Array_Display()`**:
   - Displays all elements of the array `Arr`.

4. **`FindEven()`**:
   - Iterates through `Arr`, identifying even numbers and storing them in the `Even` array.
   - Displays the even numbers.

5. **`FindOdd()`**:
   - Identifies odd numbers and stores them in the `Odd` array.
   - Displays the odd numbers.

6. **`TotalEven()`**:
   - Calculates and returns the sum of all even numbers.

7. **`TotalOdd()`**:
   - Calculates and returns the sum of all odd numbers.

### Program Flow
The `main()` function orchestrates the following sequence:
1. **Initialize UART**: Setup communication with `SerialInit()`.
2. **Array Size and Input**:
   - Prompt for array size with `Array_Size()`.
   - Collect integers using `Array_Insert(n)`.
3. **Display Array**:
   - Call `Array_Display(n)` to show all entered values.
4. **Identify and Display Even Numbers**:
   - Use `FindEven(n)` to populate and display the `Even` array.
   - Calculate and display the total of even numbers using `TotalEven(n)`.
5. **Identify and Display Odd Numbers**:
   - Use `FindOdd(n)` to populate and display the `Odd` array.
   - Calculate and display the total of odd numbers using `TotalOdd(n)`.
6. **Infinite Loop**:
   - Keep the program running.

---

## Example Output
- **Prompt**: `Enter the size of the array:`
- **User Enters**: `5`
- **Prompt**: `Enter the numbers inside the array`
  - **User Inputs**: `3`, `12`, `5`, `8`, `10`
- **Display**:
  - `These are your Array numbers: 3, 12, 5, 8, 10`
  - `Even numbers of your Array are: 12, 8, 10`
  - `Total Even numbers are: 30`
  - `Odd numbers of your Array are: 3, 5`
  - `Total Odd numbers are: 8`

---

## Algorithm

1. **Start**:
   - Include necessary libraries (`reg51.h` and `uart_int.h`).

2. **Initialize UART**:
   - Call `SerialInit()`.

3. **Array Size Input**:
   - Call `Array_Size()` to get `n`, the size of the array.

4. **Array Input**:
   - Call `Array_Insert(n)` to populate `Arr` with `n` integers from the user.

5. **Array Display**:
   - Call `Array_Display(n)` to print all numbers in `Arr`.

6. **Identify Even Numbers**:
   - Call `FindEven(n)` to find even elements and store them in `Even`.
   - Display even numbers.
   - Call `TotalEven(n)` to calculate and display the sum of even numbers.

7. **Identify Odd Numbers**:
   - Call `FindOdd(n)` to find odd elements and store them in `Odd`.
   - Display odd numbers.
   - Call `TotalOdd(n)` to calculate and display the sum of odd numbers.

8. **Infinite Loop**:
   - Enter an infinite loop to keep the program running.

---

This program provides a comprehensive example of data manipulation with an array in embedded C, particularly focusing on data filtering and summing specific array elements based on criteria (even or odd).
