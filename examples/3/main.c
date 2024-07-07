#include <stdio.h>
#include <raylib.h>

typedef enum {
    LOGO = 0,
    STARTING,
    ENDING
}gameState;

int main(void){

    InitWindow(800,420,"Wassup");

    SetTargetFPS(60);

    gameState gameScreen = LOGO;

    int timeout = 0;

    while(!WindowShouldClose()){
        

        switch (gameScreen)
        {
        case LOGO:
            timeout++;

            if (timeout >= 120){
                gameScreen = STARTING;
            }

            break;
        case STARTING:
            if (IsKeyPressed(KEY_ENTER)){
                gameScreen = ENDING;
                break;
            }
        case ENDING:
            if(IsKeyPressed(KEY_ENTER)){
                gameScreen = STARTING;
                break;
            }
        }
        

        BeginDrawing();
        

        if (gameScreen == LOGO){
            ClearBackground(BLACK);

            DrawText(TextFormat("LOGO, WAIT 2 seconds %i",timeout),0,0,32,WHITE);

        }else if(gameScreen == STARTING){
            ClearBackground(BLUE);

            DrawText("STARTING, PRESS ENTER",0,0,32,WHITE);

            
        }else if(gameScreen == ENDING){
            ClearBackground(GREEN);

            DrawText("ENDING, PRESS ENTER",0,0,32,WHITE);
        }



        EndDrawing();

    }


    CloseWindow();
    return 0;
}