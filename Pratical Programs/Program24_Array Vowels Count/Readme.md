# Microcontroller Vowel Count Program

This program, created for the 8051 microcontroller, demonstrates basic input and output operations using UART (Universal Asynchronous Receiver-Transmitter) for communication between the microcontroller and a computer. The program enables the user to define an array size, input characters into the array, and then counts how many vowels (a, e, i, o, u, A, E, I, O, U) are present in the array.
-----------------
# OUTPUT
![prg5_op](https://github.com/user-attachments/assets/d5ed5d1b-6e68-41bd-9817-c35a6513228a)


---------
# Working Proof Video
https://github.com/user-attachments/assets/e064d760-62da-47b7-9c29-32b4f45e1753
## Files
- **`main.c`**: The main program file.
- **`uart.h`**: Header file providing UART-related functions for initializing serial communication and reading/writing data between the microcontroller and a computer.

## Requirements
- An 8051 microcontroller and a development environment that supports `reg51.h` and UART-based functions.
- **`uart.h`** header file, which provides UART functions necessary for serial communication.

## Function Descriptions

### UART Functions from `uart.h`
The `uart.h` header file is used to facilitate communication between the 8051 microcontroller and the computer through UART. It contains the following functions:
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
 - Prompts the user to enter `n` characters, which are stored in the global array `Arr`.

3. **`Count_Vowels(unsigned char Array_name[], unsigned int n)`**:
 - Iterates through the array and checks for vowels (a, e, i, o, u, A, E, I, O, U).
 - Returns the total count of vowels in the array.

### Program Workflow
The `main()` function manages the program flow:
1. Initializes the UART communication.
2. Calls `Array_Size()` to determine the array size.
3. Calls `Array_Insert()` to gather user input for the array.
4. Calls `Count_Vowels()` to count the vowels in the array.
5. Displays the total number of vowels to the user.
6. Enters an infinite loop to keep the program running.

---

## Algorithm

1. **Start**:
 - Include the required libraries: `reg51.h` for the 8051 microcontroller and `uart.h` for UART functions.

2. **Initialize UART**:
 - Call `SerialInit()` to set up serial communication.

3. **Array Size Input**:
 - Call `Array_Size()`:
   - Prompt the user to enter the array size (up to 10).
   - Store the entered size in variable `n`.

4. **Array Input**:
 - Call `Array_Insert(n)`:
   - Prompt the user to enter `n` characters.
   - Store each character in the `Arr` array.

5. **Count Vowels**:
 - Call `Count_Vowels(n)`:
   - Iterate over the array and check each character.
   - Count the characters that match any of the vowels (a, e, i, o, u, A, E, I, O, U).
   - Store the vowel count in the variable `count`.

6. **Display Results**:
 - Use `SendInt2PC()` to display the total number of vowels in the array.

7. **Infinite Loop**:
 - Enter an infinite loop (`while(1);`) to keep the program running.

---

## Example Output

- **Prompt**: `Enter the size of the Array:`
- **User Enters**: `5`
- **Prompt**: `Enter a character (a-z or A-Z):`
- **User Inputs**: `a`, `b`, `i`, `o`, `u`
- **Display**:
- `Total Numbers of Vowels in your array is: 4`

---

This program demonstrates a basic input-output operation with array manipulation and vowel counting in embedded C for the 8051 microcontroller. It is useful for learning data handling and communication between microcontrollers and computers over UART.
