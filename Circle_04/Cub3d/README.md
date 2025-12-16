# Cub3D 🕹️

Cub3D is a **3D raycasting game engine** inspired by *Wolfenstein 3D*, built in **C** using the **MLX42 (Codam)** graphics library.  
This project is part of the **42 Network curriculum** and focuses on graphics programming, mathematics, and low-level system concepts.

---

## ✨ Features

- Real-time **raycasting engine**
- Textured walls with correct perspective
- Player movement (W / A / S / D)
- Camera rotation with keyboard and mouse
- Mouse look (bonus)
- Floor and ceiling rendering
- Mini-map (bonus)
- Doors & hand animation (bonus)
- Collision detection

---

## 🎮 Controls

| Key / Input | Action |
|------------|--------|
| W / S | Move forward / backward |
| A / D | Strafe left / right |
| ← / → / ↑ / ↓ | Rotate camera |
| SPACE | Open / close doors |
| Mouse | Look around |
| ESC | Exit game |

---

## 🧠 Concepts Learned

- Raycasting mathematics
- Perspective projection
- Texture mapping
- Event handling & game loop logic
- Mouse input handling
- Collision detection
- Memory management in C

---

## 🛠️ Installation

```bash
git clone https://github.com/alemdaar/1337---Common-Core-Projects.git cc
cd cc/Circle_04/Cub3d
make clone_mlx42
make
```

Or build the bonus version:

```bash
make bonus
```

---

## ▶️ Usage

### Mandatory
```bash
./cub3d maps/mandatory/basic.cub
```

### Bonus
```bash
./cub3d maps/bonus/bn.cub
```

---

## 🗺️ Map Rules

| Symbol | Meaning |
|-------|---------|
| `1` | Wall |
| `0` | Empty space |
| `N S E W` | Player start position |
| `D` | Door (bonus) |

- Maps must be **closed and surrounded by walls**

---

## 📁 Project Structure

```
cub3d/
├── src/
├── lib/
├── maps/
├── textures/
├── Makefile
└── README.md
```

---

## 🚀 Bonus Part

- Mouse look in all directions
- Animated hand & doors
- Mini-map system

---

## 👥 Authors

**Oussama El Hassouni** (with a classmate)  
42 Network – 1337 Coding School  
UM6P (Mohammed VI Polytechnic University)

---

## 📜 License

This project is developed for **educational purposes only** as part of the 42 curriculum.

