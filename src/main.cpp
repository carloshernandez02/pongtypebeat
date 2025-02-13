#include<raylib.h>
#include "Ball\Ball.cpp"
#include "paddles\Paddle.cpp"


int main()
{
    Paddle P1 = Paddle(15,KEY_W,KEY_S);
    Paddle P2 = Paddle(765,KEY_O,KEY_L);
    Ball pongBall;

    
    InitWindow(800, 600, "testing something ig");

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        P1.Update();
        P2.Update();
        pongBall.Update();

        
        if (CheckCollisionCircleRec(Vector2{pongBall.xCord, pongBall.yCord}, pongBall.radius,Rectangle{P1.xCord, P1.yCord, P1.width, P1.height}))
        {
            pongBall.speedX *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{pongBall.xCord, pongBall.yCord}, pongBall.radius,Rectangle{P2.xCord, P2.yCord, P2.width, P2.height}))
        {
            pongBall.speedX *= -1;
        }
        

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawLine(400, 0, 400, 600, WHITE);

        DrawText(TextFormat("%i",pongBall.scoreP1), 60, 20, 80, WHITE);
        DrawText(TextFormat("%i",pongBall.scoreP2), 720, 20, 80, WHITE);

        P1.Draw();
        P2.Draw();
        pongBall.Draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}