# minishell 🐚

[42 Network – Morocco]

> A simple shell implementation project created in collaboration with a classmate. Mandatory part only.

---

## 📝 Description

**minishell** is a 42 Network project that implements a simplified Unix shell. It supports executing commands, built-in commands, redirections, pipes, and basic signal handling.  

This project was completed with a classmate, focusing on teamwork and collaboration.

---

## ⚡ Features

- Executes external commands using `execve`.  
- Supports built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.  
- Handles input/output redirections (`>`, `<`, `>>`) and pipes (`|`).  
- Processes multiple commands chained with pipes.  
- Handles environment variables and expansions.  
- Basic signal handling and memory management.

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/<your-username>/1337---Common-Core-Projects.git cc
cd cc/Circle_03/minishell
```

Compile:

```bash
make
```

---

## 🚀 Usage

Run the shell:

```bash
./minishell
```

- The shell will display a prompt where you can enter commands.  
- Supports both built-in and external commands.  
- Supports redirections, pipes, and environment variable expansions.

Exit the shell with `exit` or `Ctrl+D`.

---

## 📂 Project Structure

```
minishell/
├── Makefile
├── en.subject.pdf
├── minishell.c
├── minishell.h
├── exec/
│   ├── builtins/{bin,cd,echo,env,exit,export,pwd,unset}.c
│   ├── child.c
│   ├── cmd.c
│   ├── exec.c
│   ├── exec2.c
│   ├── exit_status.c
│   ├── fds.c
│   ├── file.c
│   ├── file2.c
│   ├── free.c
│   ├── gnl/{get_next_line,get_next_line_utils}.c
│   ├── header.h
│   ├── heredoc.c
│   ├── linkedlist/linkedlist.c
│   ├── paths.c
│   ├── tools{,2,3}.c
│   └── work.c
├── libft/
│   ├── Makefile
│   ├── ft_{isalnum,isalpha,isdigit,itoa,memcpy,strcmp,strdup,strjoin,strlen,strncpy,substr}.c
│   └── libft.h
└── parsing/
    ├── asm_cmd.c
    ├── cmd/{content_cmd,list_cmd,nodes_cmd,utils_cmd}.c
    ├── envp/{clean_env,env_expander,env_heredoc,env_list,env_split,exp_special,extra,utils1_env,utils_env}.c
    ├── error/error.c
    ├── include/token.h
    ├── input/input.c
    ├── leaks/{ffree,free_cmd_list}.c
    ├── signal/{signal,signal2}.c
    ├── syntax/{scrap,utils_scrap}.c
    └── tokens_core/{list_tokens,refactor_tokens,unquotes,utils0_tokens,utils1_tokens,utils3_tokens}.c
```

- `exec` contains execution logic, built-ins, pipes, redirections, and GNL.  
- `libft` contains custom standard library functions.  
- `parsing` handles command parsing, environment management, tokens, and syntax checking.  

---

## ⚖️ Rules & Constraints

- Implement a functional shell with proper process and memory management.  
- Must handle signals correctly.  
- No memory leaks or crashes allowed.  
- Support redirections and piping.

---

## 🎯 Learning Outcomes

- Process management with `fork`, `execve`, and pipes.  
- Implementing shell built-ins and environment variable handling.  
- Command parsing and syntax checking.  
- Signal handling in a shell environment.  
- Collaboration with a teammate to manage a large C project.

---

## 👤 Authors

**Oussama Hassouni** & **Classmate**  
42 Network – Morocco

