#pragma

class Paddle
{
public:
    Paddle(int xCord, int key1, int key2);
    void Update();
    void Draw() const;
    float width, height;
    float yCord, xCord;

private:
    
    int ySpeed;
    
    int key1, key2;
};
