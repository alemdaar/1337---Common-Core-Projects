# CPP09 — The STL

> The payoff module: three real problems, each solved by choosing the right container.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Topic" src="https://img.shields.io/badge/topic-STL-22D3EE">
  <img alt="Flags" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
</p>

---

## Overview

CPP09 is the final module of the C++ piscine and the culmination of everything that came before. There is no new language feature to learn here — instead, the module is about **applying the STL well**. Each of its three exercises is an independent program built around a concrete problem, and each one is designed to push you toward a *specific* container whose properties fit the task.

The recurring lesson: a container is not a neutral choice. `std::map`, `std::stack`, `std::vector`, and `std::deque` each carry different complexity guarantees, and picking the wrong one is the difference between an elegant solution and a slow, awkward one. A hard requirement of the module is that **each exercise must use at least one — and sometimes a specific — STL container**, and you may not reuse the same container across exercises.

---

## Exercises

### ex00 — Bitcoin Exchange
A program that reads a CSV database of historical Bitcoin prices and, given an input file of `date | value` lines, outputs the value of that amount of Bitcoin on each date — using the price from that exact date, or the **closest earlier date** when an exact match is absent.

- **Container of choice:** `std::map<std::string, float>` — its sorted‑by‑key structure makes "find the closest earlier date" natural via `lower_bound`.
- **Skills:** file parsing, date validation, robust error handling for malformed input, negative values, and out‑of‑range amounts.

```bash
./btc input.txt
# 2011-01-03 => 3 = 0.9
```

### ex01 — Reverse Polish Notation (RPN)
Evaluates a mathematical expression written in postfix (Reverse Polish) notation, where operators follow their operands.

- **Container of choice:** `std::stack<int>` — the textbook data structure for RPN evaluation: push operands, pop two on each operator, push the result.
- **Skills:** tokenisation, stack‑based evaluation, division‑by‑zero and malformed‑expression handling.

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# 42
```

### ex02 — PmergeMe
Implements the **Ford‑Johnson merge‑insertion sort** — a sorting algorithm chosen specifically because it minimises comparisons — and runs it on a sequence of positive integers using **two different containers**, then reports the timing of each.

- **Containers of choice:** typically `std::vector` and `std::deque` (or `std::list`) — the exercise requires demonstrating the same algorithm on two distinct container types and comparing their performance.
- **Skills:** implementing a non‑trivial recursive algorithm, working with pairs and a Jacobsthal‑number insertion order, parsing and validating input, and measuring/reporting execution time per container.

```bash
./PmergeMe 3 5 9 7 4
# Before: 3 5 9 7 4
# After:  3 4 5 7 9
# Time to process a range of 5 elements with std::vector : 0.00031 us
# Time to process a range of 5 elements with std::deque  : 0.00042 us
```

---

## Building & running

Each exercise has its own `Makefile` and binary:

```bash
make            # build
./btc <file>            # ex00
./RPN "<expression>"    # ex01
./PmergeMe <numbers>    # ex02
make fclean     # clean everything
```

Compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

---

## Project structure

```
cpp09/
├── ex00/   # Bitcoin Exchange   (std::map)
├── ex01/   # RPN                (std::stack)
└── ex02/   # PmergeMe           (std::vector + std::deque)
```

---

## Key takeaways

- **The container is part of the algorithm.** `std::map` makes Bitcoin Exchange trivial; `std::stack` makes RPN trivial. The right structure does half the work.
- Real input is hostile — most of the effort in ex00 and ex01 is **validation and error handling**, not the core computation.
- PmergeMe shows that the *same* algorithm can perform differently depending on the container's memory layout, which is why measuring matters.
- After this module, reaching for the STL — and reasoning about complexity before writing code — becomes second nature.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
