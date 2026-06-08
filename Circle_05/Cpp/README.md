# C++ Modules — CPP05 → CPP09

> The advanced half of the 42 / 1337 C++ piscine: exceptions, casts, templates, templated containers, and the STL.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Standard" src="https://img.shields.io/badge/std-c%2B%2B98-blue">
  <img alt="Compiler" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
  <img alt="School" src="https://img.shields.io/badge/1337-42%20Network-black">
</p>

---

## Overview

These five modules form the second leg of the C++ piscine at 42. Where the first modules (00–04) cover the transition from C to object‑oriented programming — classes, references, inheritance, and polymorphism — modules **05 through 09** push into the features that make C++ genuinely *different* from C: structured error handling, a strict type‑conversion system, compile‑time genericity, and the Standard Template Library.

Every module is written in **C++98**, compiled with `-Wall -Wextra -Werror -std=c++98`, and follows the Orthodox Canonical Form where classes are involved. No external libraries, no C++11 and beyond — the constraints are deliberate, forcing a deep understanding of the language fundamentals rather than reliance on modern conveniences.

---

## The progression

| Module | Theme | Core question it answers |
|:------:|:------|:-------------------------|
| **CPP05** | Repetition & Exceptions | How do I handle errors cleanly without return codes everywhere? |
| **CPP06** | C++ Casts | How do I convert between types safely and explicitly? |
| **CPP07** | Templates | How do I write code once that works for any type? |
| **CPP08** | Templated containers, iterators & algorithms | How do I use the STL's building blocks together? |
| **CPP09** | The STL | How do I pick the right container to solve a real problem? |

The order is intentional. Exceptions (05) give you the error‑handling vocabulary used everywhere afterward. Casts (06) sharpen your understanding of the type system. Templates (07) introduce genericity, which is the foundation the STL is built on. Modules 08 and 09 then put the STL to work — first its mechanics, then its application to real algorithmic problems.

---

## Module summaries

### CPP05 — Repetition and Exceptions
Introduces C++ exception handling through the `throw` / `try` / `catch` mechanism and custom exception classes that inherit from `std::exception`. Built around a bureaucrat‑and‑forms simulation that grows from a single class to an abstract hierarchy with a factory.

**Exercises:** Bureaucrat · Form · Abstract Form + concrete forms · Intern (factory)

### CPP06 — C++ Casts
Covers the four C++ cast operators — `static_cast`, `dynamic_cast`, `reinterpret_cast`, and `const_cast` — and when each is appropriate. Includes scalar type conversion, pointer serialization, and runtime type identification.

**Exercises:** Scalar conversion · Serialization · Identify real type

### CPP07 — C++ Templates
Introduces function templates and class templates, type‑safe genericity, and template specialization. You write algorithms and data structures that work for any type without code duplication.

**Exercises:** `whatever` (swap/min/max) · `iter` · `Array` class template

### CPP08 — Templated containers, iterators, and algorithms
Brings together templates and the STL: using standard containers, iterating over them, and applying the algorithms in `<algorithm>`. Culminates in building your own container that exposes STL‑compatible iterators.

**Exercises:** `easyfind` · `Span` · `MutantStack`

### CPP09 — STL
The payoff module. Three independent programs, each forcing a deliberate choice of STL container to solve a concrete problem efficiently.

**Exercises:** Bitcoin Exchange (`std::map`) · RPN calculator (`std::stack`) · PmergeMe (Ford‑Johnson sort)

---

## Building

Each exercise ships with its own `Makefile` exposing the standard 42 rules:

```bash
make        # build the program (NAME)
make clean  # remove object files
make fclean # remove object files and the binary
make re     # fclean + make
```

All code compiles cleanly with:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

---

## Repository structure

```
cpp_modules/
├── cpp05/
│   ├── ex00/   # Bureaucrat
│   ├── ex01/   # Form
│   ├── ex02/   # Abstract Form + concrete forms
│   └── ex03/   # Intern
├── cpp06/
│   ├── ex00/   # Scalar conversion
│   ├── ex01/   # Serialization
│   └── ex02/   # Identify real type
├── cpp07/
│   ├── ex00/   # whatever
│   ├── ex01/   # iter
│   └── ex02/   # Array
├── cpp08/
│   ├── ex00/   # easyfind
│   ├── ex01/   # Span
│   └── ex02/   # MutantStack
└── cpp09/
    ├── ex00/   # Bitcoin Exchange
    ├── ex01/   # RPN
    └── ex02/   # PmergeMe
```

---

## Key concepts across all five modules

- **Exception safety** — using RAII and exception hierarchies so resources are never leaked when errors propagate.
- **Explicit type conversion** — choosing the narrowest, most intention‑revealing cast for the job.
- **Generic programming** — writing type‑independent code with templates and template specialization.
- **The STL** — containers (`vector`, `list`, `deque`, `stack`, `map`, `set`), iterators, and the generic algorithms that operate on them.
- **Orthodox Canonical Form** — every class implements its default constructor, copy constructor, copy‑assignment operator, and destructor.
- **Algorithmic thinking** — selecting a container by its complexity guarantees, not by habit.

---

## What these modules teach

By the end of CPP09, the recurring lesson is clear: **C++ gives you many tools, and mastery is knowing which one fits the problem in front of you.** Exceptions, casts, templates, and the STL each exist to solve a specific class of problem — they are not interchangeable, and using the wrong one is its own kind of bug. These modules build the intuition to choose well.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- GitHub: [github.com/alemdaar](https://github.com/alemdaar/1337---Common-Core-Projects)
- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
