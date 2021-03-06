#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "game_constants.h"


class Ball : public sf::CircleShape
{
    private:
        sf::Vector2f m_velocity;

    public:
        Ball(float x, float y, float radius, const sf::Vector2f &velocity);
        Ball(float x, float y, float radius, float velocity_x, float velocity_y);
        virtual ~Ball();

        void setVelocity(sf::Vector2f& velocity) { m_velocity = velocity; }
        sf::Vector2f getVelocity() { return m_velocity; }

        void invertXVelocity();
        void invertYVelocity();

        void move();
};

#endif // BALL_H
