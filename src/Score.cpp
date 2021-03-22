#include <string>
#include "Score.h"

Score::Score(sf::Font &font, unsigned int char_size, float x_position, float y_position, const sf::Color &color)
{
    setFont(font);
    setCharacterSize(char_size);
    setPosition(x_position, y_position);
    setFillColor(color);
    setString(std::to_string(m_score_value));
}

Score::~Score()
{
    //dtor
}

void Score::increaseScore()
{
    ++m_score_value;
    setString(std::to_string(m_score_value));
}
