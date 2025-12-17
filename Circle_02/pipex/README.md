# pipex 🟠

[42 Network – Morocco]

> A Unix pipeline emulator that executes commands connected by pipes. Includes mandatory and bonus parts.

---

## 📝 Description

**pipex** is a 42 Network project that simulates the behavior of shell pipelines. Given a series of commands, it executes them in order, using pipes to transfer output from one command to the next.  

This repository includes:

- **Mandatory part:** basic pipeline execution between commands.  
- **Bonus part:** multiple pipes, `here_doc` support, and extra error handling.

---

## ⚡ Features

### Mandatory

- Executes commands with piping:  
  ```bash
  ./pipex infile cmd1 cmd2 outfile
  ```  
  Equivalent to:  
  ```bash
  < infile cmd1 | cmd2 > outfile
  ```  
- Handles errors for file opening and command execution.  
- Uses `fork`, `execve`, and pipes properly.  

### Bonus

- Supports **multiple commands**:  
  ```bash
  ./pipex infile cmd1 cmd2 cmd3 ... outfile
  ```  
- Implements **here_doc** functionality:  
  ```bash
  ./pipex here_doc LIMITER cmd1 cmd2 outfile
  ```  
  Reads input until `LIMITER` is reached and pipes it into commands.  
- Enhanced error handling and memory management.  

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/alemdaar/1337---Common-Core-Projects.git cc
cd cc/Circle_02/pipex
```

Compile:

```bash
# Mandatory
make

# Bonus
make bonus
```

---

## 🚀 Usage

### Mandatory (2 commands)

```bash
./pipex infile.txt "grep hello" "wc -l" outfile.txt
```

Equivalent to:

```bash
< infile.txt grep hello | wc -l > outfile.txt
```

### Bonus (multiple commands)

```bash
./pipex infile.txt "grep hello" "cut -d' ' -f1" "sort" outfile.txt
```

### Here_doc (bonus)

```bash
./pipex here_doc END "cat" "wc -l" outfile.txt
```

Input lines until you type `END`.

---

## 📂 Project Structure

```
pipex/
├── Makefile
├── bonus/
│   ├── get_next_line/
│   │   ├── get_next_line.c
│   │   ├── get_next_line.h
│   │   └── get_next_line_utils.c
│   ├── header_bonus.h
│   ├── main_bonus.c
│   └── srcs_bonus/
│       ├── display_bonus/display_bonus.c
│       ├── execution_bonus/execution_bonus.c
│       ├── execution_bonus/execution2_bonus.c
│       ├── free_bonus/free_bonus.c
│       ├── here_doc/here_doc_bonus.c
│       ├── linkedlist_bonus/linkedlist_bonus.c
│       ├── parcing_bonus/parcing1_bonus.c
│       ├── parcing_bonus/parcing2_bonus.c
│       ├── parcing_bonus/parcing3_bonus.c
│       ├── parcing_bonus/paths_bonus.c
│       ├── tools_bonus/tools_bonus.c
│       └── tools_bonus/tools2_bonus.c
└── mandatory/
    ├── header.h
    ├── main.c
    └── srcs/
        ├── display/display.c
        ├── execution/execution.c
        ├── free/free.c
        ├── linkedlist/linkedlist.c
        ├── parcing/parcing1.c
        ├── parcing/parcing2.c
        ├── parcing/parcing3.c
        ├── parcing/paths.c
        └── tools/tools.c
```

- Mandatory folder contains core project files.  
- Bonus folder contains extended functionality, including here_doc and multiple commands.  
- `Makefile` supports compilation for both mandatory and bonus parts.

---

## ⚖️ Rules & Constraints

- Must use **fork**, **pipe**, and **execve**.  
- No use of `system()`.  
- Proper error handling for invalid files or commands.  
- Memory must be freed properly.  

---

## 🎯 Learning Outcomes

- Deep understanding of Unix pipes and process management.  
- Handling of multiple commands and dynamic input/output redirection.  
- Advanced C programming with `fork`, `execve`, `pipe`, and memory management.  
- Implementing robust error handling.  

---

## 👤 Author

**Oussama Hassouni**  
42 Network – Morocco

