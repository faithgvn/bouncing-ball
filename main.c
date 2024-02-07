#include <raylib.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "Bouncing ball by faithgvn");

    double x = 400;
    double y = 455;
    double vy = 0;
    double g = 10;
    double dt = 1.0 / 60; // 60FPS

    double obstacleX = 800;

    while (!WindowShouldClose()) {
        double t = 0;
        while (t < 1 && !WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(0, 0, 800, 490, SKYBLUE);
            if (IsKeyDown(KEY_RIGHT)) {
                x = x + 1;
            }
            if (IsKeyDown(KEY_LEFT)) {
                x = x - 1;
            }
            if (IsKeyDown(KEY_UP) && y > 454) {
                vy = -80;
            }

            if (y < 455 || vy < 0) {
                y = y + vy * dt;
                vy = vy + g * dt;
            }

            obstacleX = obstacleX - 20 * dt;

            if (obstacleX < -60) {
                obstacleX = 800;
            }

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

            Vector2 ballCenter;
            ballCenter.x = x;
            ballCenter.y = y;

            Rectangle obstacleRect;
            obstacleRect.x = obstacleX;
            obstacleRect.y = 350;
            obstacleRect.width = 60;
            obstacleRect.height = 140;

            if (CheckCollisionCircleRec(ballCenter, 35, obstacleRect)) {
                DrawText("GAME OVER", 400, 300, 10, BLACK);
            }

            DrawRectangle(obstacleX, 350, 60, 140, GRAY);

            DrawCircle(x, y, 35, RED);
            DrawRectangle(0, 490, 800, 600, GREEN);
            DrawRectangle(0, 500, 800, 600, BROWN);
            EndDrawing();

            t = t + dt;
        }
    }

    CloseWindow();

    return 0;
}
