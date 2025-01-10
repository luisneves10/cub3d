# ️‍🧊 cub3d

The Cub3d is a 42 group project that challenges you to create a basic 3D game engine inspired by Wolfenstein 3D, focusing on implementing raycasting, texture mapping, and game mechanics. This project combines mathematics, graphics programming, and user interaction.

## 🚀 Features

- **Raycasting:** Implements a basic raycasting algorithm for rendering a 3D view of a 2D map.

- **Texture Mapping:** Adds textures to walls, improving visual depth and immersion.

- **Player Movement:** Allows the player to navigate the game world with smooth movement and rotation.

- **Map Parsing:** Reads and validates map files with specific rules for structure and elements.

- **Mini Map (bonus):** Displays a 2D representation of the map for easier navigation.

## 🛠️ Technologies Used

- **C Programming Language**

- **MinilibX (MLX)**: A lightweight library for graphics programming in C.

## 📥 Installation

To run the cub3d project on your local machine, follow these steps:

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/luisneves10/cub3d.git
    ```

2. **Navigate to the Project Directory**:
    ```bash
    cd cub3d
    ```
3. **Download MLX**:
    ```bash
    make mlx
    ```

4. **Compile the Code** (mandatory or bonus part):
    ```bash
    make
    ```
    or
    ```bash
    make bonus
    ```

4. **Run the Program**:
    ```bash
    ./cub3d <map.cub>
    ```
    or
   ```bash
    ./cub3d_bonus <map.cub>
    ```
## 🕹️ Controls

- **W / S:** Move forward/backward

- **A / D:** Strafe left/right

- **Left Arrow / Right Arrow:** Rotate view

- **Mouse (bonus):** Rotate view

- **ESC:** Exit the game

## 📚 Learning Experience

- **Graphics Programming:** Gained hands-on experience with rendering and visual effects.

- **File Parsing:** Improved my skills on how to validate and interpret map files with strict requirements.

- **Optimization:** Focused on efficient algorithms to maintain real-time performance.
