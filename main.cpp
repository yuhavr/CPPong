#include <SFML/Graphics.hpp>
#include "game_constants.h"
#include "Paddle.h"
#include "Ball.h"

const sf::Vector2f paddle_size(game_constants::window_width/40, game_constants::window_height/4);

const float player1_initial_position_x = game_constants::x_distance_from_border_to_paddle;
const float player1_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

const float player2_initial_position_x = game_constants::window_width - paddle_size.x - game_constants::x_distance_from_border_to_paddle;
const float player2_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

int main()
{
    sf::RenderWindow window(sf::VideoMode(game_constants::window_width, game_constants::window_height), "CPPong");

    Paddle player1{player1_initial_position_x, player1_initial_position_y, paddle_size};
    Paddle player2{player2_initial_position_x, player2_initial_position_y, paddle_size};

    Ball ball(game_constants::window_width/2, game_constants::window_height/2, 20, 10, 10);

    ball.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (!(player1.getPosition().y < 0))
            player1.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!(player1.getPosition().y + player1.getSize().y > game_constants::window_height))
            player1.moveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (!(player2.getPosition().y < 0))
            player2.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!(player2.getPosition().y + player1.getSize().y > game_constants::window_height))
            player2.moveDown();
        }

        ball.move();

        if (ball.getPosition().y + ball.getRadius() > game_constants::window_height)
        {
            ball.invertYVelocity();
        }

        if (ball.getPosition().y - ball.getRadius() < 0)
        {
            ball.invertYVelocity();
        }

        if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) || ball.getGlobalBounds().intersects(player2.getGlobalBounds()))
        {
            ball.invertXVelocity();
        }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();
    }
    return 0;
}
