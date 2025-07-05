# 📌 CLI Calculator

## 🧠 Overview

A command-line calculator built in C that allows users to perform basic arithmetic operations: addition, subtraction, multiplication, and division. This project demonstrates my understanding of structured programming, input validation, and function decomposition in a C-based console application.

## 🛠️ Tools & Technologies Used

- **Language:** C
- **Compiler:** GCC
- **Editor:** VS Code
- **Platform:** Windows (cross-compatible with Linux/macOS)
- **Tools:** `scanf`, `printf`, modular function design

## 🎯 Features

- ✅ Displays a welcome screen and operation menu
- ✅ Accepts user input for operation selection and operands
- ✅ Handles invalid input with graceful error messages
- ✅ Prevents division by zero
- ✅ Uses clean, modular functions for readability and reusability

## 💡 What I Learned

- How to separate logic into pure functions (`add`, `sub`, `divide`, etc.)
- How to safely read user input using `scanf` and input sanitization
- How to build a menu-driven program using a `do...while` loop
- How to apply error handling and input validation in C
- The importance of clarity and organization when building CLI tools

## 🔍 For Recruiters / Reviewers

- I built this project to solidify my understanding of foundational C programming principles and to prepare for roles that involve system-level or embedded development.
- This project demonstrates my ability to:
  - Write modular and maintainable C code
  - Handle runtime errors and user input robustly
  - Apply procedural programming techniques clearly
- The code is written with future extensibility in mind (e.g., adding new operations would be simple).

## 🚀 How to Run It

```bash
# Compile
gcc -Wall -o calculator calculator.c

# Run
./calculator
```

## 📁 File Structure

```bash
calculator/
├── calculator.c
└── README.md
```

## 🧼 Future Improvements

- ⬜ Add support for exponential and moduls operations
- ⬜ Implement memory recall (store/recall last result)
- ⬜ Improve input handinling using custom parsing (instead of relying on scanf)
- ⬜ Add support for multiple operations in a single run (e.g. `1 + 2 * 3`)

## 🧑‍💻 Author

**Dalton Mosley**
[GitHub](https://github.com/DaltonMo) • [LinkedIn](https://www.linkedin.com/in/dalton-lee-mosley/)
