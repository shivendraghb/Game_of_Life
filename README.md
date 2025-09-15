# 🕹️ Conway's Game of Life (C++ + Raylib)

An interactive, graphical implementation of **Conway’s Game of Life** built in **C++** using the [raylib](https://www.raylib.com/) graphics library.  
This project is modular, with clean separation into `Grid` and `Simulation` classes for scalability and clarity.  

---

## ✨ Features

- 🎨 Graphical grid rendering with **raylib**
- 🖱️ Interactive controls:
  - **Left Click** → toggle a cell alive/dead  
  - **Enter** → start simulation  
  - **Space** → stop simulation  
  - **F** → increase speed (FPS +2)  
  - **S** → decrease speed (FPS -2, min 5)  
  - **R** → randomize grid  
  - **C** → clear grid  
  - **G** → spawn Gosper Glider Gun  
  - **H** → spawn Heart  
  - **B** → spawn Oscillating Heart  
  - **P** → spawn Pulsar  
  - **M** → spawn Super Gun (4 Gosper Guns)  

- ⚡ Adjustable simulation speed  
- 🧩 Modular C++ design:  
  - `grid.hpp / grid.cpp` → manages grid state and rendering  
  - `simulation.hpp / simulation.cpp` → Life rules & updates  
  - `code.cpp` → main game loop and event handling  

---

## 🚀 Getting Started

### 1️⃣ Clone the repo
```bash
git clone https://github.com/shivendraghb/Game_of_Life.git
cd Game_of_Life
