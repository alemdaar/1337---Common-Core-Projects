# philo 🍽️

[42 Network – Morocco]

> A concurrency project simulating the Dining Philosophers problem using threads and mutexes.

---

## 📝 Description

**philo** is a 42 Network project that simulates the Dining Philosophers problem. Philosophers alternate between thinking, eating, and sleeping while avoiding deadlocks and ensuring no philosopher starves.  

This project includes:

- Proper thread creation and management.  
- Mutexes to handle shared resources (forks).  
- Timing functions to control philosopher actions.  

---

## ⚡ Features

- Philosophers eat, sleep, and think in cycles.  
- Avoids deadlocks and ensures no philosopher starves.  
- Configurable number of philosophers and timing parameters.  
- Handles edge cases like a single philosopher.  

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/<your-username>/1337---Common-Core-Projects.git cc
cd cc/Circle_03/philosophers
```

Compile:

```bash
make
```

---

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:

```bash
./philo 5 800 200 200
```

- The optional last parameter limits the number of times each philosopher must eat.  
- Program outputs philosopher actions with timestamps.

---

## 📂 Project Structure

```
philo/
├── Makefile
├── en.subject.pdf
├── header.h
├── main.c
└── src/
    ├── algo/
    │   ├── time.c
    │   ├── work.c
    │   ├── work2.c
    │   └── work3.c
    ├── free/free.c
    ├── init/
    │   ├── init.c
    │   └── mutex.c
    ├── parcing/parcing.c
    └── tools/tools.c
```

- `src/algo` contains core philosopher routines.  
- `src/free` handles memory cleanup.  
- `src/init` initializes philosophers and mutexes.  
- `src/parcing` handles argument parsing.  
- `src/tools` contains utility functions.

---

## ⚖️ Rules & Constraints

- Must use **pthread** library for threads.  
- Must use **mutexes** for shared forks.  
- No deadlocks or data races allowed.  
- Accurate timing for actions.

---

## 🎯 Learning Outcomes

- Understanding concurrency and synchronization in C.  
- Implementing threads and mutexes safely.  
- Avoiding race conditions and deadlocks.  
- Managing program timing and resource allocation.

---

## 👤 Author

**Oussama Hassouni**  
42 Network – Morocco

