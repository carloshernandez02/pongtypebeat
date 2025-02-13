#pragma

class Ball
{
public:
    Ball();

    void Update();

    void Draw() const;
    float xCord, yCord;
    float radius;
    float speedX, speedY;
    int scoreP1, scoreP2;

};
