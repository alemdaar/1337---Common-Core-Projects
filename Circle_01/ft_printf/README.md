# ft\_printf 🖨️

**ft\_printf** is a reimplementation of the standard C `printf` function, developed as part of the **42 Network Common Core**. This project focuses on **variadic functions**, formatted output, and low-level string/number handling in C.

---

## 🎯 Project Goal

The goal of this project is to recreate the behavior of `printf` by:

- Handling **formatted output** to standard output
- Parsing format strings
- Managing **variadic arguments** using `va_list`
- Printing different data types accurately

---

## ✨ Supported Conversions

- `%c` → Character
- `%s` → String
- `%p` → Pointer address
- `%d` / `%i` → Signed integers
- `%u` → Unsigned integers
- `%x` / `%X` → Hexadecimal (lower / upper)
- `%%` → Percent sign

---

## 🧠 Concepts Learned

- Variadic functions (`va_start`, `va_arg`, `va_end`)
- Format string parsing
- Number base conversions
- Pointer representation
- Memory-safe string handling
- Modular and extensible design

---

## 📌 Function Prototype

```c
int ft_printf(const char *format, ...);
```

---

## ⚙️ How It Works (High Level)

1. Parse the format string character by character
2. Detect conversion specifiers after `%`
3. Fetch corresponding arguments using `va_arg`
4. Convert and print values based on the specifier
5. Return the total number of printed characters

---

## 🛠️ Installation

```bash
git clone https://github.com/alemdaar/1337---Common-Core-Projects.git cc
cd cc/Circle_01/ft_printf
make
```

---

## ▶️ Usage Example

```c
ft_printf("Hello %s! Number: %d, Hex: %x\n", "42", 42, 42);
```

---

## 📂 Project Structure

```
ft_printf/
├── Makefile
├── ft_pchar.c
├── ft_phex.c
├── ft_pnbr.c
├── ft_pptr.c
├── ft_printf.c
├── ft_printf.h
├── ft_putstr.c
├── ft_punsigned.c
└── README.md
```

---

## ⚠️ Important Notes

- No use of the original `printf`
- Must handle `NULL` strings safely
- Must return the correct character count
- Behavior should match the standard `printf`

---

## 🧪 Testing

Compare with the real `printf`:

```c
printf("%d\n", printf("test"));
ft_printf("%d\n", ft_printf("test"));
```

---

## 👤 Author

**Oussama El Hassouni**\
42 Network – 1337 Coding School (UM6P)

---

## 📜 License

This project is developed for **educational purposes only** as part of the 42 curriculum.

