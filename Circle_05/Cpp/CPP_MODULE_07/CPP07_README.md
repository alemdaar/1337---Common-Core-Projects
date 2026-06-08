# CPP07 — C++ Templates

> Write it once, use it with any type. The foundation everything in the STL is built on.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Topic" src="https://img.shields.io/badge/topic-templates-F59E0B">
  <img alt="Flags" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
</p>

---

## Overview

CPP07 introduces **templates** — the C++ feature for writing generic, type‑independent code. Instead of duplicating a function or class for every type it might operate on, you write a single template and let the compiler generate a concrete version for each type used. This is *compile‑time* genericity: there is no runtime cost, and full type safety is preserved.

Templates are the bedrock of the Standard Template Library, so this module is the natural bridge into CPP08 and CPP09.

---

## Concepts covered

### Function templates
A single function definition parameterised by one or more types.

```cpp
template <typename T>
T max(T const& a, T const& b) {
    return (a > b) ? a : b;
}

max(3, 7);        // T = int
max(2.5, 1.5);    // T = double
```

### Class templates
A class parameterised by type, so the same data structure works for any element type.

```cpp
template <typename T>
class Array {
    // works as Array<int>, Array<std::string>, ...
};
```

### Template instantiation
The compiler generates a distinct concrete function or class for each set of template arguments actually used — and only for those. Code that's never instantiated is never compiled into the binary.

### `const` correctness with templates
Templates must be written carefully with references and `const` so they work for both modifiable and read‑only arguments.

---

## Exercises

### ex00 — Start with a few functions (`whatever`)
Three function templates:

- `swap(a, b)` — exchanges the values of two arguments
- `min(a, b)` — returns the smaller (the second when equal)
- `max(a, b)` — returns the larger (the second when equal)

The gentle introduction: the same template works for `int`, `float`, `std::string`, or any type supporting the required operators.

### ex01 — `iter`
A function template that applies a given function to **every element of an array**:

```cpp
template <typename T>
void iter(T* array, size_t length, void (*f)(T&));
```

`iter` takes an array address, its length, and a function (or function template) to call on each element. A first taste of passing behaviour as a parameter — the seed of the STL's algorithm model.

### ex02 — `Array`
A class template implementing a dynamic array with:

- A default constructor creating an empty array
- A constructor `Array<T>(unsigned int n)` allocating `n` default‑constructed elements
- A deep‑copying copy constructor and assignment operator (modifying a copy must never affect the original)
- `operator[]` with bounds checking that throws `std::exception` on an out‑of‑range index
- A `size()` member function

This ties together templates, the Orthodox Canonical Form, operator overloading, exceptions, and manual memory management with `new[]` / `delete[]`.

---

## Building & running

```bash
make            # build
./program       # run (binary name varies per exercise)
make fclean     # clean everything
```

Compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

> **Note:** template definitions live in header files (often `.hpp` or `.tpp`), because the compiler needs the full definition at every instantiation point.

---

## Project structure

```
cpp07/
├── ex00/   # whatever (swap, min, max)
├── ex01/   # iter
└── ex02/   # Array<T>
```

---

## Key takeaways

- Templates eliminate code duplication **without** sacrificing type safety or runtime performance.
- Generic code must be written defensively — references, `const`, and operator requirements all matter.
- `Array<T>` is essentially a hand‑built `std::vector` precursor, which makes the STL feel far less magical afterward.
- Passing functions to `iter` foreshadows how STL algorithms accept predicates and operations.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
