🕹️ Conway's Game of Life (C++ + Raylib)

An interactive, graphical implementation of Conway’s Game of Life built in C++ using the raylib
 graphics library.
The project is modular and split into Grid and Simulation classes for clarity and scalability.

✨ Features

🎨 Graphical grid rendering with raylib

🖱️ Interactive controls:

Left Click → toggle a cell alive/dead

Enter → start simulation

Space → stop simulation

F → increase speed (FPS +2)

S → decrease speed (FPS -2, min 5)

R → randomize grid

C → clear grid

G → spawn Gosper Glider Gun

H → spawn Heart

B → spawn Oscillating Heart

P → spawn Pulsar

M → spawn Super Gun (4 Gosper Guns)

⚡ Adjustable simulation speed

🧩 Modular codebase:

grid.hpp / grid.cpp → manages grid state and rendering

simulation.hpp / simulation.cpp → updates cells with Life rules

code.cpp → game loop and user input

🚀 Getting Started
1️⃣ Clone the repo
git clone https://github.com/your-username/GameOfLife.git
cd GameOfLife

2️⃣ Install dependencies

Install raylib

Make sure g++ (MinGW on Windows, GCC/Clang on Linux/macOS) is installed

3️⃣ Build
🔹 Linux / macOS
make
./build/game

🔹 Windows (PowerShell + MinGW)
g++ src/code.cpp src/grid.cpp src/simulation.cpp -o build/game.exe -std=c++17 -I"C:\raylib\raylib-5.5_win64_mingw-w64\include" -L"C:\raylib\raylib-5.5_win64_mingw-w64\lib" -lraylib -lopengl32 -lgdi32 -lwinmm
.\build\game.exe
