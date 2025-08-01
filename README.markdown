# 🔢 Arbitrary Precision Calculator 🌟

Welcome to the **Arbitrary Precision Calculator (APC)**, a powerful C-based tool designed to perform arithmetic operations on numbers of unlimited size with pinpoint precision! 🚀 Break free from the constraints of standard data types and dive into a world of massive calculations for scientific, financial, or cryptographic applications. 🧮

---

## 🌍 Project Overview

The Arbitrary Precision Calculator is a command-line application that handles addition, subtraction, multiplication, and division of arbitrarily large numbers. Using doubly linked lists to represent digits, it ensures accurate computations regardless of number size, making it ideal for scenarios where `int`, `long`, or `double` fall short. 💪

---

## ✨ Key Features

- **➕ Addition**: Sum two large numbers with ease.
- **➖ Subtraction**: Compute differences, handling negative numbers gracefully.
- **✖️ Multiplication**: Multiply massive numbers efficiently.
- **➗ Division**: Perform division with precise quotient results.
- **🔄 Flexible Input**: Supports positive and negative numbers via a simple command-line interface.
- **📜 Custom Data Structure**: Uses doubly linked lists for dynamic number representation.

---

## 🛠️ Project Structure

The project is neatly organized into modular C files, each focusing on specific functionality:

- **`main.c`**: The driver program with a user-friendly interface and core list operations (`insert_last`, `insert_first`, `print_list`, `delete_list`).
- **`apc.h`**: Header file defining structures, constants, and function prototypes.
- **`addition.c`**: Implements addition of large numbers.
- **`subtraction.c`**: Handles subtraction with borrow logic.
- **`multiplication.c`**: Performs multiplication using iterative addition.
- **`division.c`**: Computes division via repeated subtraction.

---

## 🚀 Getting Started

### Prerequisites
- A C compiler (e.g., `gcc`)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`)

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/arbitrary-precision-calculator.git
   cd arbitrary-precision-calculator
   ```
2. Compile the project:
   ```bash
   gcc -o apc main.c addition.c subtraction.c multiplication.c division.c
   ```
3. Run the calculator:
   ```bash
   ./apc
   ```

---

## 🎮 How to Use

1. **Launch the Program**:
   Run the executable:
   ```bash
   ./apc
   ```

2. **Enter Input**:
   Provide two numbers and an operator in the format:
   ```
   Enter <operator1> <operand> <operator2>
   ```
   Example: `123456 + 789012` or `-456 * 789`

3. **View Results**:
   The result is displayed immediately. For example:
   ```
   123456 + 789012
   912468
   ----------------------------------
   Want to continue? Press [yY | nN]: 
   ```

4. **Continue or Exit**:
   Press `y` or `Y` to perform another calculation, or `n` or `N` to exit.

---

## 📂 Number Representation

- **Data Structure**: Numbers are stored as doubly linked lists (`Dlist`), where each node holds a single digit (0-9).
- **Order**: Digits are stored from least significant (tail) to most significant (head).
- **Negative Numbers**: Handled via flags (`neg_flag1`, `neg_flag2`) and adjusted in the result.
- **Result Storage**: Results are stored in a separate result list (`headR`, `tailR`) and printed digit-by-digit.

---

## 🎉 Example in Action

**Input**:
```
Enter <operator1> <operand> <operator2>
123456789 + 987654321
```

**Output**:
```
1111111110
----------------------------------
Want to continue? Press [yY | nN]: y
```

**Another Input**:
```
Enter <operator1> <operand> <operator2>
-456 * 789
```

**Output**:
```
-359784
----------------------------------
Want to continue? Press [yY | nN]: n
```

---

## 💡 Tips & Notes
- **Input Format**: Ensure numbers are entered as strings (e.g., `123456`) and operators are `+`, `-`, `*`, or `/`.
- **Negative Numbers**: Prefix with `-` (e.g., `-123`).
- **Zero Handling**: Division by zero or empty lists are managed gracefully.
- **Memory Management**: The program frees allocated memory after each operation to prevent leaks.
- **Large Numbers**: Tested for numbers with thousands of digits, but ensure sufficient memory for massive inputs.

---

## 🤝 Contributing

We welcome contributions to make APC even better! 🎉
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/cool-enhancement`).
3. Commit your changes (`git commit -m 'Add cool enhancement'`).
4. Push to the branch (`git push origin feature/cool-enhancement`).
5. Open a pull request.

Report bugs or share ideas via GitHub Issues! 🐛

---

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## 🌈 Why This Project?

The Arbitrary Precision Calculator is a thrilling dive into low-level programming, data structures, and algorithm design! Whether you're a student exploring linked lists, a developer tackling big-number arithmetic, or a curious coder, APC offers a rewarding challenge and practical utility. Start calculating the uncalculable today! 🚀