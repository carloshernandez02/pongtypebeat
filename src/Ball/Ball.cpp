#include "Ball.h"
#include <raylib.h>
#include <cstdlib>
#include <iostream>

float RandomSpeed(){
    srand(time(0));
    return rand() % 10 + 8.34;
}

Ball::Ball()
    : xCord(400)
    , yCord(300)
    , speedX(RandomSpeed())
    , speedY(10)
    , radius(RandomSpeed())
    , scoreP1(0)
    , scoreP2(0)
{}

void Ball::Update(){
    xCord +=speedX;
    yCord +=speedY;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if(yCord + radius >= screenHeight){
        speedY = RandomSpeed();
        speedY *=-1;
    }else if (yCord - radius<=0)
    {
        speedY = RandomSpeed();
    }
    

    if(xCord + radius >= screenWidth){
        yCord = screenHeight/2;
        xCord = screenWidth/2;
        speedX = RandomSpeed();
        speedX *=-1;
        scoreP1++;
    }else if (xCord - radius<=0)
    {
        yCord = screenHeight/2;
        xCord = screenWidth/2;
        speedX = RandomSpeed();
        scoreP2++;
    }
    
}

void Ball::Draw() const{
    DrawCircle(xCord, yCord, radius, WHITE);
}