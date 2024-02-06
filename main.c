#include <raylib.h>
#include <utils.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "Bouncing ball by faithgvn");

    int x = 400;
    int y = 455;
    int vy = 0;
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
        if (IsKeyDown(KEY_UP)) {
            vy = 1;
        }

        if (y < 200) {
            vy = -1;
        }

        TRACELOG(LOG_INFO, "x: %5d \t y: %5d \t vy: %5d", x, y, vy);

        y -= vy;

        if (y > 455) {
            y = 455;
        }
        if (y < 35) {
            y = 35;
        }
        if (x > 765) {
            x = 765;
        }
        if (x < 35) {
            x = 35;
        }

        DrawCircle(x, y, 35, RED);
        DrawRectangle(0, 490, 800, 600, GREEN);
        DrawRectangle(0, 500, 800, 600, BROWN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
