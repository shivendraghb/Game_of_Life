#include <iostream>
#include <vector>
#include <utility>
#include "simulation.hpp"
using namespace std;

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    vector<pair<int, int>> neighborOffsets = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0},  {1, 1}

    };

    for(const auto& offset : neighborOffsets) {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }
    return liveNeighbors;
}

void Simulation::Update()
{
    if(IsRunning()) {
        for(int row = 0; row < grid.GetRows(); ++row) {
            
            for(int column = 0; column < grid.GetColumns(); ++column) {
                
                int liveNeighbors = CountLiveNeighbors(row, column);
                
                if(grid.GetValue(row, column) == 1) {
                    
                    if(liveNeighbors < 2 || liveNeighbors > 3) {
                        tempGrid.SetValue(row, column, 0); // Cell dies
                    } else {
                        tempGrid.SetValue(row, column, 1); // Cell lives
                    }
                } 
                else {
                    
                    if(liveNeighbors == 3) {
                        tempGrid.SetValue(row, column, 1); // Cell becomes alive
                    } else {
                        tempGrid.SetValue(row, column, 0); // Cell remains dead
                    }
                }
            }
        }
        // Swap grids
        grid = tempGrid; 
    }
}

void Simulation::ClearGrid()
{
    if(!IsRunning()) {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(!IsRunning()) {
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int column) {
    if(!IsRunning()) {
        grid.ToggleCell(row, column);
    }
}

void Simulation::CreateGliderGun(int startRow, int startCol)
{
    if(IsRunning()) return;
    grid.Clear();

    // Gosper Glider Gun cells relative to startRow/startCol
    vector<pair<int, int>> cells = {
        {0, 24},
        {1, 22}, {1, 24},
        {2, 12}, {2, 13}, {2, 20}, {2, 21}, {2, 34}, {2, 35},
        {3, 11}, {3, 15}, {3, 20}, {3, 21}, {3, 34}, {3, 35},
        {4, 0}, {4, 1}, {4, 10}, {4, 16}, {4, 20}, {4, 21},
        {5, 0}, {5, 1}, {5, 10}, {5, 14}, {5, 16}, {5, 17}, {5, 22}, {5, 24},
        {6, 10}, {6, 16}, {6, 24},
        {7, 11}, {7, 15},
        {8, 12}, {8, 13}
    };

    for(auto [r, c] : cells) {
        grid.SetValue(startRow + r, startCol + c, 1);
    }
}

void Simulation::CreateHeart(int startRow, int startCol)
{
    if(IsRunning()) return;
    grid.Clear();

    // Pixel-art style heart (symmetrical, ~11x10 size)
    vector<pair<int, int>> heart = {
        {0,2}, {0,3}, {0,6}, {0,7},
        {1,1}, {1,4}, {1,5}, {1,8},
        {2,0}, {2,9},
        {3,0}, {3,9},
        {4,1}, {4,8},
        {5,2}, {5,7},
        {6,3}, {6,6},
        {7,4}, {7,5}
    };

    for(auto [r, c] : heart) {
        grid.SetValue(startRow + r, startCol + c, 1);
    }
}

void Simulation::CreateOscillatingHeart(int startRow, int startCol)
{
    if(IsRunning()) return;
    grid.Clear();

    // Heart state 1
    vector<pair<int, int>> heart1 = {
        {0,3}, {0,4}, {0,7}, {0,8},
        {1,2}, {1,5}, {1,6}, {1,9},
        {2,1}, {2,10},
        {3,1}, {3,10},
        {4,2}, {4,9},
        {5,3}, {5,8},
        {6,4}, {6,7},
        {7,5}, {7,6}
    };

    // Heart state 2 (slightly "expanded")
    vector<pair<int, int>> heart2 = {
        {0,3}, {0,4}, {0,7}, {0,8},
        {1,2}, {1,5}, {1,6}, {1,9},
        {2,1}, {2,10}, {2,5}, {2,6},
        {3,0}, {3,11},
        {4,1}, {4,10},
        {5,2}, {5,9},
        {6,3}, {6,8},
        {7,4}, {7,7},
        {8,5}, {8,6}
    };

    // Place first heart pattern
    for(auto [r, c] : heart1) {
        grid.SetValue(startRow + r, startCol + c, 1);
    }

    // 💡 Trick: embed second state as "neighboring cells"
    // so Conway’s rules naturally cycle it back and forth
    for(auto [r, c] : heart2) {
        grid.SetValue(startRow + r, startCol + c, 1);
    }
}

void Simulation::CreatePulsar(int startRow, int startCol) {
    if(IsRunning()) return;
    grid.Clear();

    vector<pair<int,int>> pulsar = {
        {2,4}, {2,5}, {2,6}, {2,10}, {2,11}, {2,12},
        {7,4}, {7,5}, {7,6}, {7,10}, {7,11}, {7,12},
        {9,4}, {9,5}, {9,6}, {9,10}, {9,11}, {9,12},
        {14,4}, {14,5}, {14,6}, {14,10}, {14,11}, {14,12},

        {4,2}, {5,2}, {6,2}, {10,2}, {11,2}, {12,2},
        {4,7}, {5,7}, {6,7}, {10,7}, {11,7}, {12,7},
        {4,9}, {5,9}, {6,9}, {10,9}, {11,9}, {12,9},
        {4,14}, {5,14}, {6,14}, {10,14}, {11,14}, {12,14}
    };

    for (auto [r, c] : pulsar) {
        grid.SetValue(startRow + r, startCol + c, 1);
    }
}

void Simulation::CreateSuperGun() {
    if(IsRunning()) return;
    grid.Clear();

    auto addGun = [&](int startRow, int startCol) {
        vector<pair<int,int>> gun = {
            {0, 24},
            {1, 22}, {1, 24},
            {2, 12}, {2, 13}, {2, 20}, {2, 21}, {2, 34}, {2, 35},
            {3, 11}, {3, 15}, {3, 20}, {3, 21}, {3, 34}, {3, 35},
            {4, 0}, {4, 1}, {4, 10}, {4, 16}, {4, 20}, {4, 21},
            {5, 0}, {5, 1}, {5, 10}, {5, 14}, {5, 16}, {5, 17}, {5, 22}, {5, 24},
            {6, 10}, {6, 16}, {6, 24},
            {7, 11}, {7, 15},
            {8, 12}, {8, 13}
        };

        for (auto [r, c] : gun) {
            grid.SetValue(startRow + r, startCol + c, 1);
        }
    };

    // Place 4 guns in different quadrants
    addGun(5, 5);            // top-left
    addGun(5, 40);           // top-right
    addGun(40, 5);           // bottom-left
    addGun(40, 40);          // bottom-right
}
