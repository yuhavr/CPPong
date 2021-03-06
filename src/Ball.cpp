#include "Ball.h"

Ball::Ball(float x, float y, float radius, const sf::Vector2f &velocity)
{
    setOrigin(radius, radius);
    setPosition(x, y);
    setRadius(radius);
    m_velocity = velocity;
}

Ball::Ball(float x, float y, float radius, float velocity_x, float velocity_y)
{
    setOrigin(radius, radius);
    setPosition(x, y);
    setRadius(radius);
    m_velocity.x = velocity_x;
    m_velocity.y = velocity_y;
}

Ball::~Ball()
{

}

void Ball::invertXVelocity()
{
    m_velocity.x *= -1;
}
void Ball::invertYVelocity()
{
    m_velocity.y *= -1;
}

void Ball::move()
{
    Shape::move(m_velocity.x * game_constants::dt, m_velocity.y * game_constants::dt);
}
