#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Score : public sf::Text
{
    private:
        unsigned int m_score_value = 0;

    public:
        Score(sf::Font &font, unsigned int char_size, float x_position, float y_position, const sf::Color &color);
        virtual ~Score();

        void increaseScore();
        void setScore(unsigned int score) { m_score_value = score; }
        unsigned int getScore() { return m_score_value; }
};

#endif // SCORE_H
