_This project has been created as part of the 42 curriculum by **pabartoc** (42 Heilbronn)._

# fractol

## Description
This project involves creating graphically beautiful fractals using the MiniLibX library. 
The goal of *fract-ol* is to explore the mathematical concept of complex numbers and apply them to computer graphics rendering, optimizing the calculation of mathematical sets like the Mandelbrot set, Julia set, and the Burning Ship fractal. 

The rendering engine maps a 2D window to the complex plane and calculates the escape time algorithm for every single pixel to generate a hypnotic, infinite visualization.

## Features
- **3 Different Fractals:** Mandelbrot, Julia, and Burning Ship.
- **Infinite Zoom:** Zoom in and out smoothly using the mouse wheel. The zoom follows the actual mouse position.
- **Fluid Navigation:** Move around the fractal plane using the `Arrow Keys` or `W, A, S, D`.
- **Dynamic Psychedelic Coloring:** Press `Spacebar` to shift the color range dynamically and create pulsating wave effects.
- **Cross-Platform:** The codebase dynamically handles X11 (Linux) and MacOS (Metal) keyboard event mapping and MLX window destruction under the hood.

## Instructions

## Project Structure

The code is strictly modularized to respect the 42 Norminette (max. 5 functions per file).

```text
.
├── Makefile                    # Compilation rules and flags
├── README.md                   # Project documentation
├── minilibx-linux/             # MiniLibX graphical library for Linux (X11)
├── minilibx_macos_metal/       # MiniLibX graphical library for macOS (Metal)
├── inc
│   └── fractol.h               # Main header, structs & prototypes
├── libft                       # Custom Standard C Library
│   ├── Makefile
│   ├── inc
│   │   └── libft.h
│   └── src
│       ├── ft_putstr_fd.c
│       ├── ft_strncmp.c
│       └── ... (additional libft functions)
└── src
    ├── events.c                # Mouse and keyboard input handlers
    ├── ft_atof.c               # Ascii-to-float conversion for complex numbers
    ├── init.c                  # MLX setup, window creation & data initialization
    ├── main.c                  # Argument parsing and initial program flow
    ├── render.c                # Math calculation & pixel drawing loop
    ├── utils.c                 # Cross-platform display wrappers & math helpers
    └── validation.c            # Strict error checking for user input
```

---

### Compilation
The project includes a `Makefile` that complies with the 42 Norm.
```bash
# Compile the project
make

# Clean object files
make clean

# Clean everything including the executable
make fclean

# Recompile the entire project
make re

### Memory Leak Testing (Valgrind)
The project is strictly secured against memory leaks. All dynamically allocated memory (MLX pointers, window instances, images) is properly freed upon exit. To verify this on Linux:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./fractol mandelbrot
```

## Usage
Run the program by passing the name of the desired fractal as a parameter. 
```bash
./fractol mandelbrot
./fractol burningship
./fractol julia <real> <imaginary>
```

### Examples
For the Julia set, you must define the shape by passing the real and imaginary parts of the complex number c as starting parameters:
```bash
# Classic spiraling Julia set
./fractol julia -0.8 0.156

# The "Dendrite" fractal (looks like lightning bolts)
./fractol julia 0.0 1.0

# The "Douady's Rabbit" fractal
./fractol julia -0.12256 0.74486
```

## The Mathematics & Coloring Engine
The fractals are calculated using the formula Z_{n+1} = Z_n^2 + c. For every pixel, the program iterates this calculation up to `max_iter = 42`. 

### The Core (Trapped Pixels)
If a coordinate is close to the center (e.g., c = 0), the value never escapes the safe radius (Distance² <= 4).
- **Iteration 1:** Z = 0
- **Iteration 2:** Z = 0
- **...**
- **Iteration 42:** Z = 0 (Still inside!)
- **Result:** The loop reaches `max_iter`. The pixel belongs to the core of the fractal and is assigned the dark brown base color (`0x4A2E04`).

### The Aura (Escaping Pixels)
If a coordinate is further out (e.g., c = 1 + 1i), it grows rapidly.
- **Iteration 1:** Length² = 2 (Safe)
- **Iteration 2:** Length² = 10 (Escaped!)
- **Result:** The loop breaks early at i = 2. 
The color is dynamically calculated using bit-shifting based on the escape iteration to create deep purple gradients: `(((i) * 13 % 256) << 16) | (((i) * 4 % 256) << 8) | ((i) * 18 % 256)`.

## Technical Choices
- **Optimized Math:** Avoided the overhead of importing `<math.h>` by writing a custom, lightweight `ft_abs_double` function for the Burning Ship fractal.
- **RGB Bit-Shifting:** Colors are not hardcoded but generated on the fly by manipulating the Red, Green, and Blue channels using bitwise operators (`<<` and `|`).

## Resources
- **MiniLibX Documentation:** [Harm Smits 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)
- **Mandelbrot Set:** [Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- **Julia Set:** [Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- **Burning Ship Fractal:** [Wikipedia](https://en.wikipedia.org/wiki/Burning_Ship_fractal)

### AI Usage
*As required by the project guidelines, AI tools (LLMs) were utilized during the development of this project to:*
1. Grasp the complex mathematical concepts (linear interpolation/mapping).
2. Understand the differences between macOS (Metal) and Linux (X11) architectures to resolve specific MiniLibX linker errors and keycode discrepancies.
3. Design the dynamic RGB bit-shifting palette for the fractal rendering.