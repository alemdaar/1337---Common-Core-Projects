# so_long 🎮

[42 Network – Morocco]

> A simple 2D game using the MiniLibX library. Includes mandatory and bonus parts.

---

## 📝 Description

**so_long** is a 42 Network project that creates a simple 2D game where a player collects items and reaches an exit. The goal is to handle the game map, player movement, and game logic correctly.  

This repository includes:

- **Mandatory part:** core game with player movement, collectibles, and exit.  
- **Bonus part:** enhanced features like enemy characters, animated sprites, and improved UI.

---

## ⚡ Features

### Mandatory

- Load and validate a game map from a `.ber` file.  
- Player can move using keyboard controls (`W`, `A`, `S`, `D` or arrow keys).  
- Collect all collectibles and reach the exit to win.  
- Detect invalid maps (walls, invalid characters, unreachable exits).  
- Count and display the number of moves.  

### Bonus

- Animated player and collectible sprites.  
- Enemies that move autonomously.  
- Game window resize handling.  
- Enhanced visuals with images and custom sprites.  
- Sound effects for movement or game events (if implemented).  

---

## 🛠 Installation & Compilation

Clone the repository:

```bash
git clone https://github.com/<your-username>/1337---Common-Core-Projects.git cc
cd cc/Circle_02/so_long
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

### Mandatory

```bash
./so_long maps/map_normal.ber
```

### Bonus

```bash
./so_long_bonus maps/map_bonus.ber
```

Controls:

- `W` / `Up Arrow` – Move up  
- `A` / `Left Arrow` – Move left  
- `S` / `Down Arrow` – Move down  
- `D` / `Right Arrow` – Move right  
- `ESC` – Exit game  

Collect all items and reach the exit to win.

---

## 📂 Project Structure

```
so_long/
├── Makefile
├── bonus/
│   ├── display/display_bonus.c
│   ├── display/itoa_bonus.c
│   ├── game/draw_map_bonus.c
│   ├── game/setup_bonus.c
│   ├── header_bonus.h
│   ├── main_bonus.c
│   └── parcing/
│       ├── extra_bonus.c
│       ├── free_bonus.c
│       ├── map_name_bonus.c
│       ├── parcing1_bonus.c
│       ├── parcing2_bonus.c
│       ├── parcing3_bonus.c
│       └── tools_bonus.c
├── get_next_line/
│   ├── get_next_line.c
│   ├── get_next_line.h
│   └── get_next_line_utils.c
├── mandatory/
│   ├── display/display.c
│   ├── game/draw_map.c
│   ├── game/setup.c
│   ├── header.h
│   ├── main.c
│   └── parcing/
│       ├── extra.c
│       ├── free.c
│       ├── map_name.c
│       ├── parcing1.c
│       ├── parcing2.c
│       ├── parcing3.c
│       └── tools.c
├── maps/
│   ├── map_b_large.ber
│   ├── map_b_small.ber
│   ├── map_bonus.ber
│   ├── map_large.ber
│   ├── map_normal.ber
│   └── map_small.ber
└── picss/
    ├── coin.xpm
    ├── empty.xpm
    ├── enemy.xpm
    ├── enemy2.xpm
    ├── exit.xpm
    ├── player.xpm
    └── wall.xpm
```

- Mandatory folder contains core game files (`so_long`).  
- Bonus folder contains enhanced features (`so_long_bonus`).  
- `Makefile` supports compilation for both mandatory and bonus parts.  

---

## ⚖️ Rules & Constraints

- Must use **MiniLibX** for rendering.  
- Handle **memory allocation** properly.  
- Validate maps strictly.  
- Handle user input and window events.  

---

## 🎯 Learning Outcomes

- Mastery of 2D grid representation and movement logic.  
- Handling graphics with MiniLibX.  
- Event-driven programming for user input.  
- Advanced C programming: memory management, modular code.  
- Implementing bonus features like animations and enemies.  

---

## 👤 Author

**Oussama Hassouni**  
42 Network – Morocco

