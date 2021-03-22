#include <SFML/Graphics.hpp>
#include "game_constants.h"
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

const sf::Vector2f paddle_size(game_constants::window_width/40, game_constants::window_height/4);

const float player1_initial_position_x = game_constants::x_distance_from_border_to_paddle;
const float player1_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

const float player2_initial_position_x = game_constants::window_width - paddle_size.x - game_constants::x_distance_from_border_to_paddle;
const float player2_initial_position_y = game_constants::window_height/2 - paddle_size.y/2;

int main()
{
    sf::RenderWindow window(sf::VideoMode(game_constants::window_width, game_constants::window_height), "CPPong");

    float paddle_speed { 20 };

    Paddle player1{player1_initial_position_x, player1_initial_position_y, paddle_size, paddle_speed};
    Paddle player2{player2_initial_position_x, player2_initial_position_y, paddle_size, paddle_speed};

    sf::Font game_font;

    if (!game_font.loadFromFile("assets/fonts/arcade_classic.ttf"))
    {
        player1.setFillColor(sf::Color::Red);
    }

    Score player1_score(game_font, game_constants::font_size, static_cast<float>(game_constants::window_width)/4, static_cast<float>(game_constants::window_height)/15);
    Score player2_score(game_font, game_constants::font_size, static_cast<float>(3*game_constants::window_width)/4, static_cast<float>(game_constants::window_height)/15);

    float ball_radius { 15 };
    float ball_speed { 10 };

    Ball ball{game_constants::window_width/2, game_constants::window_height/2, ball_radius, ball_speed};

    ball.setVelocity(1, -1);

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

        player1.setVelocity(0);
        player2.setVelocity(0);

        auto old_player1_position = player1.getPosition();
        auto old_player2_position = player2.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (!(player1.getPosition().y < 0))
            player1.setVelocity(-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!(player1.getPosition().y + player1.getSize().y > game_constants::window_height))
            player1.setVelocity(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (!(player2.getPosition().y < 0))
            player2.setVelocity(-1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (!(player2.getPosition().y + player1.getSize().y > game_constants::window_height))
            player2.setVelocity(1);
        }

        if ((ball.getPosition().y + ball.getRadius() > game_constants::window_height) || (ball.getPosition().y - ball.getRadius() < 0))
        {
            ball.invertYVelocity();
        }

        ball.move();

        if (ball.collides_with(player1))
        {
            player1.reflect(ball);
        }

        if (ball.collides_with(player2))
        {
            player2.reflect(ball);
        }

        player1.move();
        player2.move();

        if (ball.getPosition().x < game_constants::window_width/4)  // checking ball's position to not check collision with second paddle
        {
            if (ball.collides_with(player1))            // if paddle moves into ball, then don't move it :)
            {
                player1.setPosition(old_player1_position);
            }
        }
        else if (ball.getPosition().x > 3*game_constants::window_width/4)
        {
            if (ball.collides_with(player2))
            {
                player2.setPosition(old_player2_position);
            }
        }

        if (ball.getPosition().x + ball.getRadius() > game_constants::window_width)
        {
            player1_score.increaseScore();
            ball.setPosition(game_constants::window_width/2, game_constants::window_height/2);
        }

        if (ball.getPosition().x - ball.getRadius() < 0)
        {
            player2_score.increaseScore();
            ball.setPosition(game_constants::window_width/2, game_constants::window_height/2);
        }

        if (player1_score.getScore() > 10 || player2_score.getScore() > 10)
        {
            break;
        }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.draw(player1_score);
        window.draw(player2_score);
        window.display();
    }
    return 0;
}
