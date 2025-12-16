# Cub3D 🕹️
Cub3D is a 3D game engine inspired by Wolfenstein 3D, built in C using the MLX42 (Codam) graphics library. The project is part of the 42 Network curriculum and focuses on understanding raycasting, graphics, and low-level programming.


# Features
Real-time raycasting engine
Textured walls with correct perspective
Player movement (W/A/S/D)
Camera rotation with keyboard and mouse
Mouse look (bonus)
Floor and ceiling rendering
Mini-map (bonus)
Doors & hand animation (bonus)
Collision detection


# Controls
Key /               Input	Action
W / S / A  / D       Move forward / backward / Strafe left / right
← / → / up / down	Rotate camera
space               open/close the door
Mouse               Look around
ESC                 Exit game


# Concepts Learned
Raycasting mathematics
Perspective projection
Texture mapping
Event handling
Game loop logic
Mouse input handling
Memory management in C


# Installation
git clone https://github.com/alemdaar/1337---Common-Core-Projects.git cc 
cd cc/Circle_04/Cub3d
make clone_mlx42
make
< or >
make bonus
# Usage
    ->mandatory
        ./cub3d maps/mandatory/basic.cub
    ->bonus
        ./cub3d maps/bonus/bn.cub


# Map Rules
1       : Wall
0       : Empty space
N S E W : Player start position
D       : Door (bonus)
Map must be closed/surrounded by walls !


# Project Structure
cub3d/
├── src/
├── lib/
├── maps/
├── textures/
├── Makefile
└── README.md


# Bonus Part
Mouse look all direction
Animated hand & doors
Mini-map


# Authors

Oussama El Hassouni with a classmate
42 Network – 1337 Coding School - Um6p (Mohammed VI Polytechnic University)


📜 License
This project is for educational purposes as part of the 42 curriculum.