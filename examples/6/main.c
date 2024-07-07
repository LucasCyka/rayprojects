#include<stdio.h>
#include<raylib.h>
#include<raymath.h>


int main(int argc, char **argv){

    const int windowWidth = 800;
    const int windowHeigth = 450;
    int falling = 0;
    InitWindow(windowWidth,windowHeigth,"Raylib Platformer");

    SetTargetFPS(60);

    Rectangle player = {0,0,60,60};
    Vector2 playerVelocity = {0,0};
    Rectangle floor = {-6000,60,10000,200};
    Camera2D camera = {0};
    camera.zoom = 1.0f;

    int i = 0;
    int t = 0;
    while(!WindowShouldClose()){

        camera.target =(Vector2){ player.x,player.y};
        camera.offset = (Vector2) {windowWidth/2,windowHeigth/2};
        camera.zoom = Clamp(camera.zoom + (float)GetMouseWheelMove()*0.05f,0.7f,2.0f);

        player.x += playerVelocity.x;
        player.y += playerVelocity.y;


        if(IsKeyDown(KEY_RIGHT)){
            playerVelocity.x = 1.0f;
        }else if (IsKeyDown(KEY_LEFT)){
            playerVelocity.x = -1.0f;
        }else playerVelocity.x = 0;

        if(IsKeyPressed(KEY_SPACE) && !falling){
            playerVelocity.y -= 5.0f;
        }

        if (player.y < 0){
            falling = 1;
        }

        if (playerVelocity.y != 0 && falling) {
            playerVelocity.y += 0.1;
        }

        if (falling && CheckCollisionRecs(player,floor)){
            playerVelocity.y = 0;
            falling = 0;
        }

        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode2D(camera);

            DrawRectangle(0,-40,100,100,GRAY);

            DrawRectangleRec(floor,GREEN);
            DrawRectangle(player.x,player.y,player.width,player.height,RED);

        EndMode2D();

        DrawText("Arrow keys to move",0,0,24,BLUE);
        DrawText("Space to jump",0,24,24,BLUE);

        EndDrawing();


    }

    CloseWindow();


}