#include <raylib.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    InitWindow(800, 600, "Bouncing ball by faithgvn");

    double x = 400;
    double y = 455;
    double vy = 0;
    double g = 10;
    double dt = 1.0 / 60; // 60FPS
    int scoreboard = 0;
    double obstacleX = 800;
    bool isGameOver = false;
    char buffer[16] = { 0 };

    while (!WindowShouldClose()) {

        double t = 0;
        while (t < 1 && !WindowShouldClose()) {

            /* Read Keyboard Inputs */
            bool isJumpRequested = IsKeyDown(KEY_UP);
            bool isRestartRequested = IsKeyDown(KEY_SPACE);

            /* Do logic */
            if (isRestartRequested) {
                /* Reset everthing*/
                x = 400;
                y = 455;
                vy = 0;
                scoreboard = 0;
                obstacleX = 800;
                isGameOver = false;
                memset(buffer, 0, 16);
            }

            if (isJumpRequested && y > 454) {
                vy = -70;
            }

            if (y < 455 || vy < 0) {
                y = y + vy * dt;
                vy = vy + g * dt;
            }

            obstacleX = obstacleX - 30 * dt;

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
                isGameOver = true;
            }
            if ((ballCenter.x == obstacleRect.x + 25) && !isGameOver) {
                scoreboard = scoreboard + 1;
            }
            /* Draw everthing */

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(0, 0, 800, 490, SKYBLUE);
            DrawRectangle(obstacleX, 350, 60, 140, GRAY);
            DrawCircle(x, y, 35, RED);
            DrawRectangle(0, 490, 800, 600, GREEN);
            DrawRectangle(0, 500, 800, 600, BROWN);
            DrawText("scoreboard", 10, 10, 20, BLACK);
            memset(buffer, 0, 16);
            DrawText(itoa(scoreboard, buffer, 10), 10, 30, 20, BLACK);

            if (isGameOver) {
                DrawText("GAME OVER", 250, 300, 50, BLACK);
                DrawText("Press space to restart", 200, 200, 30, BLACK);
            }

            EndDrawing();

            t = t + dt;
        }
    }

    CloseWindow();

    return 0;
}
