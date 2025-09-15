#include <iostream>
#include <raylib.h>
#include "simulation.hpp"

using namespace std;

int main () {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 10; 
    int fps = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(fps);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    
    
    /*
    ------- Simulation Loop -------
            
         -> Evennt Eandling
         -> Updating State
         -> Drawing Objects
    
    */
    while(WindowShouldClose() == false) {
        // 1. Event Handling
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }
        if(IsKeyPressed(KEY_ENTER)) {
            simulation.Start();
            SetWindowTitle("Game of Life - Running");
        }
        else if(IsKeyPressed(KEY_SPACE)) {
            simulation.Stop();
            SetWindowTitle("Game of Life - Stopped");
        }
        else if(IsKeyPressed(KEY_F)) {
            fps += 2;
            SetTargetFPS(fps);
        }
        else if(IsKeyPressed(KEY_S)) {
            
            if(fps > 5) {
                fps -= 2;
                SetTargetFPS(fps);
            }
        }
        else if(IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }
        else if(IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }
        else if(IsKeyPressed(KEY_G)) {
            simulation.CreateGliderGun(10, 10);
        }
        else if(IsKeyPressed(KEY_H)) {
            simulation.CreateHeart(10, 10);
        }
        else if(IsKeyPressed(KEY_B)) {
            simulation.CreateOscillatingHeart(10, 10);
        }
        else if(IsKeyPressed(KEY_P)) {
            simulation.CreatePulsar(20, 20); // Big pulsar at (20,20)
        }
        else if(IsKeyPressed(KEY_M)) {
            simulation.CreateSuperGun();
        }

        // 2. Updating State
        simulation.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}
