# CPP00 - C++ Module 00

This repository contains the exercises for **C++ Module 00 (CPP00)** from 42 School.
The goal is to learn the basics of **C++ programming** including **OOP, classes, constructors, destructors, namespaces, and standard streams**.

---

## 📌 Exercises

### **ex00 - Hello, C++**
**Objective:** Write a simple program that prints "Hello World!" using standard output.

**Files:**
- `ex00.cpp`

**Concepts Learned:**
- `std::cout` for console output
- `std` namespace
- Basic C++ program structure

**Example:**
```bash
$ ./ex00
Hello World!
```

---

### **ex01 - PhoneBook**
**Objective:** Implement a simple PhoneBook application using **classes and OOP principles**.

**Files:**
- `Contact.hpp` / `Contact.cpp` — Contact class definition and implementation
- `PhoneBook.hpp` / `PhoneBook.cpp` — PhoneBook class definition and implementation
- `main.cpp` — User interface

**Key Concepts:**
- Classes and objects
- Constructors and destructors
- Encapsulation (`private` / `public` members)
- Member functions
- Standard I/O (`std::cout`, `std::cin`)
- Initialization lists
- Arrays of objects (`Contact contacts[8]`)

**Functionality:**
- Add a contact with first name, last name, nickname, phone number, and darkest secret
- Search and display contacts in a table
- Maximum of 8 contacts, with index-based search

**Example Run:**
```bash
$ ./PhoneBook
Enter a command: ADD
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves C++

Enter a command: SEARCH
|     Index|First Name| Last Name|  Nickname
|         0|      John|       Doe|        JD
Select index: 0
First name: John
Last name: Doe
Nickname: JD
Phone number: 123456789
Darkest secret: Loves C++
```

---

## 🛠 Compilation

**Makefile included:**
```bash
# Compile ex00
make ex00

# Compile ex01
make ex01

# Compile all exercises
make
```

**Run:**
```bash
./ex00
./ex01
```

---

## 💡 Notes / Best Practices

- Avoid `using namespace std;` in headers
- Use `const` member functions where possible
- Validate user input (no empty fields)
- Follow OOP principles for clean code
- No dynamic memory (`new` / `delete`) allowed in CPP00

---

## 👤 Author
Oussama Hassouni  
CPP00 - 42 School