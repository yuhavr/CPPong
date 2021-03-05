#include "game_constants.h"
#include "Paddle.h"


Paddle::Paddle(float x_pos, float y_pos, const sf::Vector2f& paddle_size)
{
    setPosition(x_pos, y_pos);
    setSize(paddle_size);
}

Paddle::~Paddle()
{
    //dtor
}

void Paddle::moveUp()
{
    move(0, -1*m_velocity*game_constants::dt);
}

void Paddle::moveDown()
{
    move(0, m_velocity*game_constants::dt);
}
