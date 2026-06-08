# CPP06 — C++ Casts

> Four cast operators, four very different jobs. Choosing the right one is the whole point.

<p align="left">
  <img alt="Language" src="https://img.shields.io/badge/language-C%2B%2B98-00599C">
  <img alt="Topic" src="https://img.shields.io/badge/topic-type%20conversion-A78BFA">
  <img alt="Flags" src="https://img.shields.io/badge/flags-Wall%20Wextra%20Werror-success">
</p>

---

## Overview

CPP06 is about **explicit type conversion** in C++. Where C has a single, blunt cast syntax — `(type)value` — that silently does whatever it takes to reinterpret one type as another, C++ splits conversion into four named operators, each with a precise meaning and a different level of safety.

The module teaches not just *how* to use each cast, but *when*: the goal is to always reach for the narrowest, most intention‑revealing cast that gets the job done, so that the code documents its own assumptions.

---

## The four casts

### `static_cast<T>`
Compile‑time conversion between related types: numeric conversions, and up/down the inheritance tree when the relationship is known and safe. The everyday cast.

```cpp
double d = 3.14;
int    i = static_cast<int>(d);   // 3
```

### `dynamic_cast<T>`
Runtime‑checked conversion across a polymorphic class hierarchy. Returns `NULL` (for pointers) or throws `std::bad_cast` (for references) when the object is not actually of the requested type. Requires at least one virtual function in the base class.

```cpp
Base* b = getSomething();
if (Derived* d = dynamic_cast<Derived*>(b))
    d->derivedOnly();
```

### `reinterpret_cast<T>`
Reinterprets the raw bit pattern of a value as another type. Powerful and dangerous — no checking whatsoever. Used for low‑level work such as storing a pointer in an integer.

### `const_cast<T>`
Adds or removes `const` (or `volatile`) qualifiers. The only cast that can legally strip `const`.

---

## Exercises

### ex00 — Conversion of scalar types
A program that takes a string representation of a C++ scalar (`char`, `int`, `float`, or `double`) and converts it to all four types, printing each result — or reporting when a conversion is impossible, non‑displayable, or out of range. Also handles the special pseudo‑literals: `nan`, `+inf`, `-inf`, `inff`, etc.

This exercise is a deep practical study of `static_cast` and the edge cases of numeric conversion: overflow, precision loss, non‑printable characters, and special floating‑point values.

```bash
./convert 42
./convert nan
./convert 0
```

### ex01 — Serialization
Demonstrates `reinterpret_cast` by round‑tripping a pointer through an integer type:

- `serialize(Data* ptr)` returns a `uintptr_t` raw representation
- `deserialize(uintptr_t raw)` converts it back to `Data*`

The deserialized pointer must equal the original. A focused lesson in when reinterpreting raw memory is legitimate.

### ex02 — Identify real type
Given a `Base*` pointing at one of three derived classes (`A`, `B`, `C`) chosen at random, identify the actual type — both with a pointer (using `dynamic_cast` and `NULL` checks) and with a reference (using `dynamic_cast` inside a `try/catch`). The canonical demonstration of runtime type identification.

---

## Building & running

```bash
make            # build
./convert <literal>   # ex00 usage
make fclean     # clean everything
```

Compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

---

## Project structure

```
cpp06/
├── ex00/   # Scalar conversion
├── ex01/   # Serialization
└── ex02/   # Identify real type
```

---

## Key takeaways

- **`static_cast`** for safe, related conversions — your default.
- **`dynamic_cast`** when you need a runtime guarantee about an object's real type.
- **`reinterpret_cast`** only for deliberate, low‑level bit reinterpretation.
- **`const_cast`** only to adjust `const`/`volatile`, never as a workaround for bad design.
- Naming the cast forces you to state your intent — which makes wrong assumptions visible in code review.

---

## Author

**Oussama El Hassouni** — 1337 Coding School (UM6P) / 42 Network

- LinkedIn: [linkedin.com/in/oussama-el-hassouni](https://www.linkedin.com/in/oussama-el-hassouni-024228362/)
