#include <SFML/Graphics.hpp>
#include "game_constants.h"
#include "Paddle.h"

const sf::Vector2f paddle_size(game_constants::window_width/40, game_constants::window_height/4);

const int player1_initial_position_x = game_constants::x_distance_from_border_to_paddle;
const int player1_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

const int player2_initial_position_x = game_constants::window_width - paddle_size.x - game_constants::x_distance_from_border_to_paddle;
const int player2_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

int main()
{
    sf::RenderWindow window(sf::VideoMode(game_constants::window_width, game_constants::window_height), "CPPong");

    Paddle player1{player1_initial_position_x, player1_initial_position_y, paddle_size};
    Paddle player2{player2_initial_position_x, player2_initial_position_y, paddle_size};

    player1.setFillColor(sf::Color::Red);
    player1.setFillColor(sf::Color::Red);

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

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.display();
    }
    return 0;
}
