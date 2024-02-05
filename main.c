#include <raylib.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "Bouncing ball by faithgvn");

    int x = 400;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, 0, 800, 490, SKYBLUE);
        if (IsKeyDown(KEY_RIGHT)) {
            x = x + 1;
        }
        if (IsKeyDown(KEY_LEFT)) {
            x = x - 1;
        }
        DrawCircle(x, 455, 35, RED);
        DrawRectangle(0, 490, 800, 600, GREEN);
        DrawRectangle(0, 500, 800, 600, BROWN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
