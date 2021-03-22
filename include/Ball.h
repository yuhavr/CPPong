#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "game_constants.h"
#include "Paddle.h"
#include <random>

class Paddle;

class Ball : public sf::CircleShape
{
    private:
        float m_speed;
        sf::Vector2f m_velocity;

    public:
        Ball(float x, float y, float radius, float speed);
        virtual ~Ball();

        float getSpeed() {return m_speed; }
        void setSpeed(float speed) { m_speed = speed; }

        void setVelocity(sf::Vector2f& velocity) { m_velocity = velocity; }
        void setVelocity(float velocity_x, float velocity_y) { m_velocity.x = velocity_x; m_velocity.y = velocity_y; }
        sf::Vector2f getVelocity() { return m_velocity; }

        bool collides_with(Paddle &paddle);

        void invertXVelocity();
        void invertYVelocity();

        void randomizeVelocity();

        void move();
};

#endif // BALL_H
