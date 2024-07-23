#include "include/raylib.h"

void ball_touchingX (float &speedBallX){
    speedBallX = -speedBallX;
}
void ball_touchingY (float &speedBallY){
    speedBallY = -speedBallY;
}
void life_counter_P1 (int &countP1, int &countP2){
    if (countP1 == 3){
        DrawText("L", 125, 800 / 4, 40, DARKGRAY);
        DrawText("I", 125, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 120, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 120, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 125, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("3", 120, 800 / 4 + 225, 40, DARKGRAY);
    }else if (countP1 == 2){
        DrawText("L", 125, 800 / 4, 40, DARKGRAY);
        DrawText("I", 125, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 120, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 120, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 125, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("2", 120, 800 / 4 + 225, 40, DARKGRAY);
    }else if (countP1 == 1){
        DrawText("L", 125, 800 / 4, 40, DARKGRAY);
        DrawText("I", 125, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 120, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 120, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 125, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("1", 125, 800 / 4 + 225, 40, DARKGRAY);
    }else {
        countP1 = 3;
        countP2 = 3;
    }
}
void life_counter_P2 (int &countP2, int &countP1){
    if (countP2 == 3){
        DrawText("L", 1075, 800 / 4, 40, DARKGRAY);
        DrawText("I", 1080, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 1075, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 1075, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 1080, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("3", 1075, 800 / 4 + 225, 40, DARKGRAY);
    }else if (countP2 == 2){
        DrawText("L", 1075, 800 / 4, 40, DARKGRAY);
        DrawText("I", 1080, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 1075, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 1075, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 1080, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("2", 1075, 800 / 4 + 225, 40, DARKGRAY);
    }else if (countP2 == 1){
        DrawText("L", 1075, 800 / 4, 40, DARKGRAY);
        DrawText("I", 1080, 800 / 4 + 50, 40, DARKGRAY);
        DrawText("F", 1075, 800 / 4 + 100, 40, DARKGRAY);
        DrawText("E", 1075, 800 / 4 + 150, 40, DARKGRAY);
        DrawText("..", 1080, 800 / 4 + 175, 40, DARKGRAY);
        DrawText("1", 1080, 800 / 4 + 225, 40, DARKGRAY);
    }else {
        countP2 = 3;
        countP1 = 3;
    }
}
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    float vy = 6;

    bool inGame = false;

    //Player 1
    const int xP1 = 20;
    float yP1 = screenHeight / 2 - 50;
    float widthP1 = 20;
    float heightP1 = 100;

    int countP1 = 3;

    //Player 2
    const int xP2 = screenWidth - 40;
    float yP2 = screenHeight / 2 - 50;
    float widthP2 = 20;
    float heightP2 = 100;

    int countP2 = 3;

    //Ball
    const int radius = 10;
    float xBall = screenWidth / 2;
    float yBall = screenHeight / 2;
    float speedBallX = GetRandomValue(3, 7);
    float speedBallY = GetRandomValue(2, 5);

    int delta = GetRandomValue(1, 2);
    if (delta == 1) ball_touchingX(speedBallX);

    int alfa = GetRandomValue(1, 2);
    if (alfa == 1) ball_touchingY(speedBallY);

    int temp = 0;


    InitWindow(screenWidth, screenHeight, "ping pong");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyPressed(KEY_SPACE)){
            inGame = true;
        }
        if (inGame) {
            //Player 1
            if (yP1 > 0) {
                if (IsKeyDown(KEY_W)) {
                    yP1 -= vy;
                }
            }
            if (yP1 < screenHeight - heightP1) {
                if (IsKeyDown(KEY_S)) {
                    yP1 += vy;
                }
            }

            //Player 2
            if (yP2 > 0) {
                if (IsKeyDown(KEY_UP)) {
                    yP2 -= vy;
                }
            }
            if (yP2 < screenHeight - heightP2) {
                if (IsKeyDown(KEY_DOWN)) {
                    yP2 += vy;
                }
            }

            //Ball
            if (xBall < 34){
                inGame = false;
                xBall = screenWidth / 2;
                yBall = screenHeight / 2;
                speedBallX = GetRandomValue(2, 5);
                speedBallY = GetRandomValue(1, 3);
                yP1 = screenHeight / 2 - 50;
                yP2 = screenHeight / 2 - 50;

                countP1--;
            }else if (xBall > screenWidth - 34) {
                inGame = false;
                xBall = screenWidth / 2;
                yBall = screenHeight / 2;
                speedBallX = GetRandomValue(2, 5);
                speedBallY = GetRandomValue(1, 3);
                yP1 = screenHeight / 2 - 50;
                yP2 = screenHeight / 2 - 50;

                countP2--;
            }else{
                if (xBall <= 40 && xBall >= 34 || xBall >= screenWidth - 40 && xBall <= screenWidth - 34) {
                    if (yP1 < yBall && yBall < (yP1 + heightP1)) {
                        ball_touchingX(speedBallX);
                    } else if (yP2 < yBall && yBall < (yP2 + heightP2)) {
                        ball_touchingX(speedBallX);
                    }
                }
                xBall += speedBallX;

                if (yBall <= 10 || yBall >= screenHeight - 10) {
                    ball_touchingY(speedBallY);
                }
                yBall += speedBallY;

                //incrase ball speed
                temp++;
                if (temp % 1250 == 0) {
                    if (speedBallY < 0) {
                        speedBallY = -speedBallY;
                        speedBallY++;
                        speedBallY = -speedBallY;
                    } else speedBallY++;
                    if (speedBallX < 0) {
                        speedBallX = -speedBallX;
                        speedBallX++;
                        speedBallX = -speedBallX;
                    } else speedBallX++;
                }
            }
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GRAY);

        DrawText("GAME", screenWidth / 2 - 145, screenHeight / 6, 100, DARKGRAY);
        if (!inGame){
            DrawText("OVER", screenWidth / 2 - 145, screenHeight / 4 + 20, 100, DARKGRAY);
            DrawText("Press space to start!", screenWidth / 2 - 115, screenHeight / 3 + 50, 20, DARKGRAY);
        }

        //Player 1
        DrawRectangle(xP1, yP1, widthP1, heightP1, BLACK);

        life_counter_P1 (countP1, countP2);

        //Player 2
        DrawRectangle(xP2, yP2, widthP2, heightP2, BLACK);

        life_counter_P2 (countP2, countP1);

        //Ball
        DrawCircle(xBall, yBall, radius, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

