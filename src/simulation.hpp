#pragma once
#include "grid.hpp"
using namespace std;

class Simulation {
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {/*grid.FillRandom();*/};
        void Draw();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
        void Update();
        bool IsRunning() {return run;}
        void Start() {run = true;}
        void Stop() {run = false;}
        void ClearGrid();
        void CreateRandomState();
        void ToggleCell(int row, int column);
        void CreateGliderGun(int startRow, int startCol);
        void CreateHeart(int startRow, int startCol);
        void CreateOscillatingHeart(int startRow, int startCol);
        void CreatePulsar(int startRow, int startCol);
        void CreateSuperGun();
    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};
