# push_swap 🟢

[42 Network – Morocco]

> A sorting algorithm project using stacks, limited operations, and optimized moves. Includes both mandatory and bonus parts.

---

## 📝 Description

**push_swap** is a 42 Network project that challenges you to sort a stack of integers using only a restricted set of stack operations. The goal is to minimize the number of moves while handling any input size efficiently.  

This repository includes:

- **Mandatory part:** core sorting logic and operations.  
- **Bonus part:** checker program and enhanced error handling.

---

## ⚡ Features

### Mandatory

- Sort integers using only allowed operations:  
  `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`  
- Optimized to minimize total operations.  
- Handles small and large datasets efficiently.  

### Bonus

- `checker_bonus` verifies if a stack is sorted correctly.  
- Reads operations from standard input.  
- Handles errors and edge cases robustly (duplicates, already sorted stacks, invalid input).  
- Supports large inputs efficiently.

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/<your-username>/push_swap.git
cd push_swap
```

Compile:

```bash
# Mandatory
make

# Bonus
make bonus
```

---

## 🚀 Usage

### push_swap (mandatory)

```bash
./push_swap 4 3 2 1
```

Output: a sequence of operations to sort the stack.

### checker (bonus)

```bash
./checker 4 3 2 1
```

Then input operations line by line:

```text
pb
ra
sa
...
```

Output:  
- `OK` → stack sorted  
- `KO` → stack not sorted  

---

## 📂 Project Structure

```
push_swap/
│
├── Makefile
├── en.subject.pdf
├── checker_bonus.c
├── checker_bonus.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── operation2_bonus.c
├── operation3_bonus.c
├── operation4_bonus.c
├── operation5_bonus.c
├── operation6_bonus.c
├── operation7_bonus.c
├── operation8_bonus.c
├── operation_bonus.c
├── mandatory/
│   ├── functions1.c
│   ├── functions2.c
│   ├── functions3.c
│   ├── functions4.c
│   ├── functions5.c
│   ├── functions6.c
│   ├── functions7.c
│   ├── functions8.c
│   ├── functions9.c
│   ├── functions10.c
│   ├── functions11.c
│   ├── functions12.c
│   ├── header.h
│   └── push_swap.c
```

- `_bonus.c` files contain bonus functionality.  
- Mandatory folder contains the core project files.  
- `Makefile` supports both mandatory and bonus compilation.

---

## ⚖️ Rules & Constraints

- Use **stacks only**, no arrays for sorting.  
- No **global variables**.  
- Allowed C standard functions: `write`, `malloc`, `free`, `exit`.  
- Proper **error handling** for invalid input, duplicates, or non-integer values.

---

## 🎯 Learning Outcomes

- Mastery of stack data structure operations.  
- Algorithm optimization for minimal moves.  
- Advanced C programming: memory management and pointers.  
- Robust handling of edge cases and input validation.

---

## 👤 Author

**Oussama Hassouni**  
42 Network – Morocco