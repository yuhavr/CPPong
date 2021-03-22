#include "Ball.h"

Ball::Ball(float x, float y, float radius, float speed)
{
    setOrigin(radius, radius);
    setPosition(x, y);
    setRadius(radius);
    setSpeed(speed);
    m_velocity = sf::Vector2f(m_speed, m_speed);
}

Ball::~Ball()
{

}

bool Ball::collides_with(Paddle &paddle)
{
    return getGlobalBounds().intersects(paddle.getGlobalBounds());
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
    Shape::move(m_velocity.x * m_speed * game_constants::dt, m_velocity.y * m_speed * game_constants::dt);
}
