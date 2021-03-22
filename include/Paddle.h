#ifndef PADDLE_H
#define PADDLE_H

#include "game_constants.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "Ball.h"

class Ball;

class Paddle : public sf::RectangleShape
{
    public:
        float m_velocity;
        float m_speed;

    public:
        Paddle(float x_pos, float y_pos, const sf::Vector2f& paddle_size, float paddle_speed);
        virtual ~Paddle();

        float getVelocity() {return m_velocity; }
        void setVelocity(float velocity) {m_velocity = velocity; }

        float getSpeed() {return m_speed; }
        void setSpeed(float speed) {m_speed = speed; }

        void move();

        void reflect(Ball &ball);
};

#endif // PADDLE_H
