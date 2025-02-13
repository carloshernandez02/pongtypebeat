#include"Paddle.h"
#include<raylib.h>

Paddle::Paddle(int xCord, int key1, int key2)
    : yCord (300 - height/2)
    , xCord(xCord)
    , ySpeed(20)
    , width(18)
    , height(120)
    , key1(key1)
    , key2(key2)
{}

void Paddle::Update(){
    if(IsKeyDown(key1))
        yCord-=ySpeed;
    if(IsKeyDown(key2))
        yCord+=ySpeed;

    const int screenHeight = GetScreenHeight();

    if(yCord + height >=screenHeight || yCord<=0){
        yCord= (yCord<=0) ? 0 :screenHeight - height;
    }
}

void Paddle::Draw() const
{
    DrawRectangle(xCord, yCord, width, height, WHITE);
}