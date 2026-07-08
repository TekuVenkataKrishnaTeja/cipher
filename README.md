# Caesar Cipher Tool (C++)

A console-based **Caesar Cipher Encryption & Decryption Tool** developed in **C++** using fundamental **Data Structures**. The application allows users to encrypt text, decrypt text, perform a brute-force attack, and undo the last encryption/decryption operation.

---

# Features

- Encode plaintext using the Caesar Cipher algorithm.
- Decode ciphertext using a specified shift value.
- Brute Force Attack to display all possible decrypted messages.
- Undo functionality using a Stack.
- Linked List implementation for storing text.
- Queue implementation during decoding.
- Bubble Sort to sort brute-force results alphabetically.
- Menu-driven console interface.

---

# Data Structures Used

| Data Structure | Purpose |
|---------------|---------|
| Linked List | Stores characters of the input text |
| Stack | Stores previous states for Undo operation |
| Queue | Used during the decoding process |
| Array | Stores brute-force outputs |
| Bubble Sort | Sorts brute-force decrypted results |

---

# Project Structure

```
Caesar-Cipher-Tool/
│
├── main.cpp
├── README.md
```

---

# Algorithm

## Encoding

1. Read input text.
2. Store characters in a linked list.
3. Save current state in the stack.
4. Apply Caesar Cipher shift.
5. Display encrypted text.
6. Allow Undo.

---

## Decoding

1. Read encrypted text.
2. Store text in linked list.
3. Push original state into stack.
4. Insert characters into queue.
5. Remove each character from queue.
6. Reverse the Caesar Cipher shift.
7. Display decrypted text.
8. Allow Undo.

---

## Brute Force Attack

1. Copy the encrypted linked list.
2. Try every possible shift (1–95).
3. Decode using each shift.
4. Store every result.
5. Sort results using Bubble Sort.
6. Display all possible plaintexts.

---

# Menu

```
=====================================
|      CAESAR CIPHER TOOL           |
=====================================
| 1. Encode                         |
| 2. Decode                         |
| 3. Brute Force Attack             |
| 4. Exit                           |
=====================================
```

---

# Sample Output

## Encode

```
Enter text:
HELLO

Enter shift:
3

Encoded Text:
KHOOR
```

---

## Decode

```
Enter text:
KHOOR

Enter shift:
3

Decoded Text:
HELLO
```

---

## Undo

```
Undo? y

After Undo:
HELLO
```

---

## Brute Force Attack

```
Brute Force Results

1 : ABC
2 : BCD
3 : CDE
...
95 : XYZ
```

---

# Functions

| Function | Description |
|----------|-------------|
| enqueue() | Inserts character into queue |
| dequeue() | Removes character from queue |
| createList() | Creates linked list from input |
| display() | Displays linked list |
| copyList() | Copies linked list |
| deleteList() | Frees memory |
| pushState() | Saves previous state |
| popState() | Retrieves previous state |
| undo() | Restores previous text |
| encode() | Encrypts text |
| decode() | Decrypts text |
| bubbleSort() | Sorts brute-force outputs |
| bruteForce() | Generates every possible decryption |

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| Encode | O(n) |
| Decode | O(n) |
| Copy Linked List | O(n) |
| Undo | O(n) |
| Bubble Sort | O(n²) |
| Brute Force | O(95 × n + 95²) |

---

# Technologies Used

- C++
- Object-Oriented Programming Concepts
- Linked List
- Queue
- Stack
- Bubble Sort
- Caesar Cipher Algorithm

---

# Learning Outcomes

This project demonstrates practical implementation of:

- Cryptography fundamentals
- Caesar Cipher encryption
- Linked Lists
- Queues
- Stacks
- Dynamic Memory Allocation
- Bubble Sort
- Brute Force Attack
- Menu-driven C++ applications

---

# Future Enhancements

- File encryption and decryption
- Graphical User Interface (GUI)
- Support for multiple cipher algorithms
- Frequency analysis attack
- Dictionary-based brute-force filtering
- Save encrypted/decrypted text to files

---

# Author

**Venkat Krishna Teja Teku**

Aspiring Cybersecurity Professional | MCA Student | C++ & Python Developer
