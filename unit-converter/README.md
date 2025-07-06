# 🧠 Unit Converter

A menu-driven CLI program in C that converts between common units of measurement such as distance, mass, and temperature. Uses a structured and extensible conversion system powered by function pointers and category-based menus.

---

## 🔍 Why This Project Matters

This project demonstrates real-world use of function pointers, custom structs, and category-based menu systems — all implemented in standard C. It highlights:

- Custom data structures (`typedef struct`)
- Modular conversion logic using function pointers
- Dynamic category handling with string comparison
- Layered control flow using nested loops and input validation

---

## 🛠️ Tech Stack

- **Language:** C
- **Tools:** GCC, VSCode
- **Concepts:** function pointers, structs, menu systems, input handling, category filtering

---

## 🚀 How to Run

### Compile

```bash
gcc -Wall -o converter main.c
```

### Run

```bash
./converter
```

> 💡 Tested on Linux and macOS. For Windows, use a compatible terminal and compiler like MinGW.

---

## 📘 What I Learned

- Using structs to organize related data (conversion label, units, function pointer)
- Implementing function pointers for modular arithmetic operations
- Filtering and managing categories using arrays and `strcmp`
- Building multi-level menu systems using nested control flow
- Validating user input and preventing common CLI bugs

---

## 📁 File Structure

```bash
unit-converter/
├── main.c
└── README.md
```

---

## 👨‍💻 Author

**Dalton Mosley**
[GitHub](https://github.com/DaltonMo) • [LinkedIn](https://www.linkedin.com/in/dalton-lee-mosley/)
