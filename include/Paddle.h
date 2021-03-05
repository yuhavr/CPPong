#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>


class Paddle : public sf::RectangleShape
{
    private:
        double m_velocity = 35;


    public:
        Paddle(float x_pos, float y_pos, const sf::Vector2f& paddle_size);
        virtual ~Paddle();

        void moveUp();
        void moveDown();


};

#endif // PADDLE_H
