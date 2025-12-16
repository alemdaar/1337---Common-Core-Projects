# get_next_line 📄

**get_next_line** is a project from the **42 Network Common Core** that focuses on reading a file **line by line** from a file descriptor in **C**, handling buffering, static variables, and memory management correctly.

---

## 🎯 Project Goal

The goal of this project is to implement a function that:

- Reads a file (or standard input) **one line at a time**
- Returns the next line at each call
- Works with **any file descriptor**
- Manages memory safely without leaks

---

## 🧠 Concepts Learned

- File descriptors
- Static variables in C
- Buffering and partial reads
- Dynamic memory allocation
- String manipulation
- Handling multiple file descriptors
- Memory leak prevention

---

## 📌 Function Prototype

```c
char *get_next_line(int fd);
```

---

## ⚙️ How It Works (High Level)

1. Read from the file descriptor using a buffer of size `BUFFER_SIZE`
2. Store unread data between calls using a static variable
3. Extract and return the next line ending with `\n`
4. Keep the remaining data for the next call
5. Return `NULL` when there is nothing left to read

---

## 🛠️ Installation

```bash
git clone https://github.com/alemdaar/1337---Common-Core-Projects.git cc
cd cc/Circle_01/get_next_line
make
```

---

## ▶️ Usage Example

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 📂 Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── Makefile
└── README.md
```

---

## ⚠️ Important Notes

- The function must not use `lseek`
- No memory leaks are allowed
- Must handle reading from `stdin`
- Must work with different `BUFFER_SIZE` values

---

## 🧪 Testing

You can test with different buffer sizes:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

---

## 👤 Author

**Oussama El Hassouni**  
42 Network – 1337 Coding School (UM6P)

---

## 📜 License

This project is developed for **educational purposes only** as part of the 42 curriculum.

