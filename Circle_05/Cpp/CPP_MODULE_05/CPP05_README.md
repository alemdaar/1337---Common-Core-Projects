# CPP05 — Repetition and Exceptions

> Learning to handle errors the C++ way: with exceptions, not return codes.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Topic" src="https://img.shields.io/badge/topic-exceptions-F87171">
  <img alt="Flags" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
</p>

---

## Overview

CPP05 is the fifth module of the 42 C++ piscine. Its theme is **repetition and exceptions** — but the repetition is just the vehicle; the real lesson is **exception handling**.

In C, errors are communicated through return values and `errno`, and the caller is trusted to check them. C++ offers a structured alternative: a function can `throw` an exception, and the runtime unwinds the call stack until a matching `catch` block handles it. This module builds the intuition for when and how to use that mechanism, through a small bureaucratic simulation of clerks signing and executing forms.

---

## Concepts covered

### Exceptions: `throw` / `try` / `catch`
The core mechanism. When an operation cannot complete, it throws an exception object instead of returning an error code. Control jumps to the nearest enclosing `catch` that matches the thrown type, skipping everything in between.

```cpp
try {
    bureaucrat.incrementGrade();   // may throw
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

### Custom exception classes
Real programs define their own exception types, typically inheriting from `std::exception` and overriding `what()` to return a meaningful message. This module introduces nested exception classes such as `Bureaucrat::GradeTooHighException`.

### Stack unwinding
When an exception propagates, every local object between the `throw` and the `catch` is destroyed in reverse order of construction. Understanding this is essential to writing leak‑free code.

### Orthodox Canonical Form
Every class implements the four canonical members: default constructor, copy constructor, copy‑assignment operator, and destructor.

---

## Exercises

### ex00 — Bureaucrat
A `Bureaucrat` has an immutable name and a grade ranging from **1 (highest)** to **150 (lowest)**. Any attempt to create or move a bureaucrat outside that range throws `GradeTooHighException` or `GradeTooLowException`. First contact with custom exceptions and the canonical form.

### ex01 — Form
Introduces a `Form` that requires a grade to **sign** and a grade to **execute**. A `Bureaucrat` signs a form only if their grade is high enough; otherwise the form throws. This exercise wires two classes together and spreads exceptions across class boundaries.

### ex02 — Abstract Form and concrete forms
`Form` becomes an **abstract base class** (`AForm`) with a pure virtual `execute()`. Three concrete forms implement real behaviour:

- **ShrubberyCreationForm** — writes ASCII trees to a file
- **RobotomyRequestForm** — succeeds 50% of the time
- **PresidentialPardonForm** — pardons a target

Each validates that the executing bureaucrat is signed in and graded high enough before acting.

### ex03 — Intern
An `Intern` is a factory: given a form name and a target, it constructs the right concrete form and returns it — no giant `if/else` chains exposed to the caller. A clean introduction to the factory pattern in C++.

---

## Building & running

```bash
make            # build
./bureaucrat    # run (binary name varies per exercise)
make fclean     # clean everything
```

Compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

---

## Project structure

```
cpp05/
├── ex00/   # Bureaucrat
├── ex01/   # Form
├── ex02/   # AForm + ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
└── ex03/   # Intern
```

---

## Key takeaways

- Exceptions separate the **happy path** from error handling, keeping core logic readable.
- A custom exception hierarchy lets callers catch broadly (`std::exception&`) or narrowly (a specific type).
- Stack unwinding makes RAII the natural way to guarantee cleanup — resources held by destroyed locals are released automatically.
- Coming from C, this is the module where `return -1;` stops being the default way to signal failure.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
