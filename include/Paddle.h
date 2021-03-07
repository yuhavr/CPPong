#ifndef PADDLE_H
#define PADDLE_H

#include "game_constants.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>


class Paddle : public sf::RectangleShape
{
    private:
        float m_velocity = 35;


    public:
        Paddle(float x_pos, float y_pos, const sf::Vector2f& paddle_size);
        virtual ~Paddle();

        float getVelocity() {return m_velocity; }
        void setVelocity(int velocity) {m_velocity = velocity; }

        void moveUp();
        void moveDown();


};

#endif // PADDLE_H
