# CPP08 — Templated Containers, Iterators, and Algorithms

> Where templates meet the STL — using standard containers, iterators, and `<algorithm>` together.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Topic" src="https://img.shields.io/badge/topic-STL%20basics-22D3EE">
  <img alt="Flags" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
</p>

---

## Overview

CPP08 is the first module to lean on the **Standard Template Library** in earnest. Having built generic code by hand in CPP07, you now use the STL's ready‑made containers, the **iterators** that traverse them, and the generic **algorithms** in `<algorithm>` that operate through those iterators.

The module's throughline is the **container / iterator / algorithm** triad — the design that lets a single algorithm like `std::find` work across `vector`, `list`, `deque`, and even custom containers, as long as they expose compatible iterators. The final exercise closes the loop by having you build a container that plugs into that ecosystem.

---

## Concepts covered

### STL containers
Standard data structures — `std::vector`, `std::list`, `std::deque`, `std::map`, `std::stack`, and more — each with its own performance trade‑offs.

### Iterators
Objects that generalise pointers, providing a uniform way to walk any container. Algorithms are written against iterators rather than concrete containers, which is what makes them universal.

```cpp
std::vector<int>::iterator it = v.begin();
for (; it != v.end(); ++it)
    std::cout << *it;
```

### Generic algorithms
Functions in `<algorithm>` such as `std::find`, `std::sort`, `std::min_element`, and `std::max_element` that take iterator ranges and operate on any compatible container.

### Building STL‑compatible types
Exposing `begin()` / `end()` and the right iterator typedefs so your own classes work with range‑based loops and standard algorithms.

---

## Exercises

### ex00 — `easyfind`
A function template `easyfind(T& container, int value)` that searches a container of integers for the first occurrence of a value, returning an iterator to it (or throwing / signalling when absent). A minimal but pointed introduction to writing generic code over **any** STL sequence container using `std::find`.

```cpp
std::vector<int> v;
// ...
easyfind(v, 42);   // returns iterator or throws if not found
```

### ex01 — `Span`
A `Span` class that stores up to **N** integers and answers two questions about them:

- `shortestSpan()` — the smallest distance between any two stored numbers
- `longestSpan()` — the largest distance between any two stored numbers

It must reject additions beyond its capacity (throwing an exception) and handle the degenerate case of fewer than two elements. A `addRange()` capability fills it from an iterator range, and the class is tested with **tens of thousands** of elements to prove it scales. This exercise is a practical study of combining containers with `<algorithm>` (`std::min_element`, `std::max_element`, sorting for adjacent differences).

### ex02 — `MutantStack`
A `MutantStack` that extends `std::stack` to make it **iterable** — something the standard `std::stack` deliberately is not. By exposing the underlying container's iterators, you can traverse a stack from bottom to top and use it with standard algorithms, while keeping all of `std::stack`'s normal behaviour. A neat demonstration of inheriting from an STL adapter and surfacing its hidden capabilities.

```cpp
MutantStack<int> s;
s.push(1); s.push(2); s.push(3);
for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it;
```

---

## Building & running

```bash
make            # build
./program       # run (binary name varies per exercise)
make fclean     # clean everything
```

Compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

---

## Project structure

```
cpp08/
├── ex00/   # easyfind
├── ex01/   # Span
└── ex02/   # MutantStack
```

---

## Key takeaways

- The STL's power comes from the **separation** of containers, iterators, and algorithms — they compose freely.
- Writing a function that accepts *any* container (`easyfind`) cements how iterators decouple algorithms from data structures.
- `Span` shows that picking the right standard algorithm turns a fiddly manual loop into one clear line.
- `MutantStack` proves the STL is extensible: you can build on its components instead of reinventing them.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
