#include <raylib.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "Bouncing ball by faithgvn");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 0, 800, 490, SKYBLUE);
        DrawCircle(250, 455, 35, RED);
        DrawRectangle(0, 490, 800, 600, GREEN);
        DrawRectangle(0, 500, 800, 600, BROWN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
