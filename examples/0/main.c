#include <raylib.h>
#include <stdio.h>
#include "test.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int a =4;
    int b = sumTest();
    //a = sumTest();
    // Main game loop
    int i = 0;
    int seconds = 0;
    while (!WindowShouldClose())
    {
        /* code */
        i = i +1;
        
        if (i % 60 == 0 ){
            seconds += 1;
        }
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        if (a == 0){
            return 0;
        }
        ClearBackground(RAYWHITE);
        char b  = i;
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        DrawText(TextFormat("Time: %i",seconds),0,0,10,BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}