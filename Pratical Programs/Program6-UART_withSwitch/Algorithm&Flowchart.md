# Algorithm for Switch-based Operations

1. **Initialize**:
   - Set up serial communication.
   - Set up switches `s1` (P1^0) and `s2` (P1^1).

2. **Display Instructions**:
   - Show instructions for switch modes:
     - Both OFF: **Addition**
     - s1 ON, s2 OFF: **Subtraction**
     - s1 OFF, s2 ON: **Multiplication**
     - Both ON: **Division**

3. **Get User Input**:
   - Ask the user to input two numbers.

4. **Check Switches**:
   - Read the states of `s1` and `s2`.

5. **Perform Operation**:
   - Based on switch states:
     - Do **Addition**, **Subtraction**, **Multiplication**, or **Division**.

6. **Show Result**:
   - Send the result to the serial output.

7. **Repeat**:
   - Wait for switch state changes and repeat the process.

--------------------------------

# Flowchart

<img src=flow6.png>
