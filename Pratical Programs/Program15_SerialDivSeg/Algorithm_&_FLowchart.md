# Algorithm

1. **Start Program**
2. **Initialize Serial Communication**
3. **Input First Number (`a`)**:
    - Prompt the user to enter the first number and store it in variable `a`.
4. **Input Second Number (`b`)**:
    - Prompt the user to enter the second number and store it in variable `b`.
5. **Check Division by Zero**:
    - If `b` is zero, display an error message: "Error: Division by zero".
    - If `b` is not zero, proceed to the next step.
6. **Perform Division**:
    - Divide `a` by `b` and store the result in variable `c`.
7. **Split Result into Nibbles**:
    - Extract the higher nibble (4 most significant bits) and store it in `t`.
    - Extract the lower nibble (4 least significant bits) and store it in `o`.
8. **Display Lower Nibble (`o`) on SEG1**:
    - Send the lower nibble to the first 7-segment display (`SEG1`).
9. **Display Higher Nibble (`t`) on SEG2**:
    - Send the higher nibble to the second 7-segment display (`SEG2`).
10. **Enter Infinite Loop**:
    - The program loops infinitely to hold the display.

11. **End Program**


---

# Flowchart

```plaintext
+-----------------------------------+
|          Start Program            |
+-----------------------------------+
              |
              v
+-------------------------------+
| Initialize Serial Communication|
+-------------------------------+
              |
              v
+-------------------------------+
|   Ask for First Number (a)     |
+-------------------------------+
              |
              v
+-------------------------------+
|   Ask for Second Number (b)    |
+-------------------------------+
              |
              v
+-------------------------------------------+
| Is b = 0? (Check for Division by Zero)    |
+-------------------------------------------+
        |                        |
        | Yes                    | No
        v                        v
+--------------------+   +-----------------------+
| Display Error:      |   |  Divide a by b        |
| "Division by Zero"  |   |  Store result in c    |
+--------------------+   +-----------------------+
        |                        |
        v                        v
+-------------------+    +----------------------------+
|     End Program    |    | Split Result into Nibbles  |
+-------------------+    +----------------------------+
                               |
                               v
                +-------------------------------+
                | Display Lower Nibble (o) on SEG1 |
                +-------------------------------+
                               |
                               v
                +-------------------------------+
                | Display Higher Nibble (t) on SEG2 |
                +-------------------------------+
                               |
                               v
                       +-------------------+
                       |   Infinite Loop   |
                       +-------------------+
