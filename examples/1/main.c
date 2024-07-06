#include<stdio.h>
#include<raylib.h>


int main(void){

    InitWindow(320,200,"My raylib project");

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLACK);
        const char mytext = TextFormat("Goodbye, World");
        DrawText(mytext,100,200,20,WHITE);


        EndDrawing();

    }


    return 0;
}