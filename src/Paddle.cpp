#include "Paddle.h"


Paddle::Paddle(float x_pos, float y_pos, const sf::Vector2f& paddle_size, float paddle_speed)
{
    setPosition(x_pos, y_pos);
    setSize(paddle_size);
    setSpeed(paddle_speed);
}

Paddle::~Paddle()
{
    //dtor
}

void Paddle::move()
{
    sf::Transformable::move(0, m_velocity*m_speed*game_constants::dt);
}

void Paddle::reflect(Ball &ball)
{
    if (ball.getPosition().y < this->getPosition().y)
    {
        ball.invertYVelocity();
    }
    else if (ball.getPosition().y > this->getPosition().y + this->getSize().y)
    {
        ball.invertYVelocity();
    }
    else
    {
        ball.invertXVelocity();
    }

}
