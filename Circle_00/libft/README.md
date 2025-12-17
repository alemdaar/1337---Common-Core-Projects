# libft 📚

[42 Network – Morocco]

> A custom C library project including mandatory and bonus functions.

---

## 📝 Description

**libft** is a 42 Network project that implements a set of standard C library functions as well as bonus linked list functions. It serves as a personal utility library for future projects.

This repository includes:

- **Mandatory functions:** string manipulation, memory management, character checks, conversions, etc.  
- **Bonus functions:** linked list operations.

---

## ⚡ Features

### Mandatory

- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`.  
- String manipulation: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strdup`, `ft_strnstr`, `ft_strjoin`, `ft_substr`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`.  
- Memory management: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`.  
- Conversion: `ft_atoi`, `ft_itoa`.  
- File descriptor output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.  

### Bonus

- Linked list operations: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`, `ft_lstlast`, `ft_lstsize`.  

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/<your-username>/libft.git
cd libft
```

Compile library:

```bash
make
```

This will create `libft.a` which can be linked to other C projects.

---

## 🚀 Usage

Link the library when compiling other projects:

```bash
gcc main.c -L. -lft -o my_program
```

Include the header in your source files:

```c
#include "libft.h"
```

---

## 📂 Project Structure

```
libft/
├── en.subject.pdf
├── ft_*.c (all mandatory functions)
├── ft_lst*.c (all bonus linked list functions)
├── libft.h
├── main.c
└── makefile
```

- `ft_*.c` contains mandatory library functions.  
- `ft_lst*.c` contains bonus linked list functions.  
- `libft.h` is the main header file.  
- `makefile` builds `libft.a`.

---

## ⚖️ Rules & Constraints

- Reimplement standard C library functions.  
- Manage memory safely (no leaks).  
- Follow Norm coding style.  
- Bonus functions: linked list utilities.

---

## 🎯 Learning Outcomes

- Mastery of core C library functions.  
- Implement linked list operations from scratch.  
- Improve memory management and pointer manipulation skills.  
- Prepare a personal utility library for future projects.

---

## 👤 Author

**Oussama Hassouni**  
42 Network – Morocco