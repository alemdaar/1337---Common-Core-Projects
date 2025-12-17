# get_next_line 📄

`get_next_line` is a C function that reads a file descriptor line by line, returning one line at each call. This project is part of the **42 Network Common Core** and focuses on static variables, memory management, and handling buffered input efficiently.

---

## Mandatory Part

### Function Prototype
```c
char *get_next_line(int fd);
```

### Behavior
- Reads from a file descriptor and returns **one line at a time**
- A line ends with `\n` or EOF
- Returns:
  - A line (including `\n`) on success
  - `NULL` on EOF or error

### Rules
- Uses a **static variable** to store leftover data between calls
- Works with any valid file descriptor
- Handles files with or without a trailing newline
- No memory leaks allowed

---

## Bonus Part ⭐

### Multiple File Descriptors Support

The bonus extends the mandatory part by allowing **simultaneous reading from multiple file descriptors**.

This means:
- Each file descriptor has its **own independent buffer**
- You can switch between FDs without losing state

Example:
```c
fd1 = open("file1.txt", O_RDONLY);
fd2 = open("file2.txt", O_RDONLY);

get_next_line(fd1); // reads from file1
get_next_line(fd2); // reads from file2
get_next_line(fd1); // continues file1 correctly
```

### Key Concepts in Bonus
- Static storage indexed by file descriptor
- Careful memory handling per FD
- Scales correctly with multiple open files

---

## Concepts Learned

- Static variables in C
- Buffer management
- File descriptors & system calls (`read`)
- Dynamic memory allocation
- Edge case handling (EOF, errors, empty files)

---

## Compilation

### Mandatory

```bash
cc -Wall -Wextra -Werror \
    -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c
```

### Bonus

```bash
cc -Wall -Wextra -Werror \
    -D BUFFER_SIZE=42 \
    get_next_line_bonus.c get_next_line_utils_bonus.c
```

---

## Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
├── README.md
```

---

## Usage Example

### Mandatory Example (Single File Descriptor)

```c
int fd;
char *line;

fd = open("file.txt", O_RDONLY);
if (fd < 0)
    return (1);

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```c
int fd;
char *line;

fd = open("file.txt", O_RDONLY);
if (fd < 0)
    return (1);

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

### Bonus Example (Multiple File Descriptors)

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
char *line;

line = get_next_line(fd1);
printf("FD1: %s", line);
free(line);

line = get_next_line(fd2);
printf("FD2: %s", line);
free(line);

line = get_next_line(fd1); // continues from file1
printf("FD1: %s", line);
free(line);

close(fd1);
close(fd2);
```

---



## Notes

- `BUFFER_SIZE` is defined at compile time
- The function is optimized to read the minimum necessary data

---

## Author

Oussama El Hassouni  
42 Network – 1337 Coding School (UM6P)

---

📜 **License**  
This project is for educational purposes as part of the 42 curriculum.

