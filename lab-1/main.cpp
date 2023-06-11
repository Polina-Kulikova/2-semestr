#include <SFML/Graphics.hpp>
#include <iostream>

class AnimatedText{
private:
    std::string m_text;
    sf::Time m_duration;
public:
    AnimatedText(std::string text, sf::Time duration)
    {
        m_text = text;
        m_duration = duration;
    }
void show(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("FerdinandFont-Regular.ttf"))
    {
        std::cout<<"Unable to load font"<<std::endl;
    }
    sf::Text text; //объект, который будет отображать текст
    text.setFont(font);
    text.setString(m_text);
    text.setCharacterSize(64);
    text.setFillColor(sf::Color::Cyan);

    sf::Time elapsed = sf::Time::Zero; //будет отслеживать прошедшее время
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (int i = 0; i < m_text.length(); i++) // цикл для отображения каждой буквы текста
        {
            text.setString(m_text.substr(0, i+1));
            text.setOrigin(100,100);
            text.setPosition(100,100);

            elapsed = sf::seconds(elapsed.asSeconds() + m_duration.asSeconds() / m_text.length()); //расчитываем задержку перед выводом следующей буквы
            sf::sleep(elapsed); //приостановка программы на elasped
            std::cout<< elapsed.asSeconds()<<std::endl;

            window.clear();
            window.draw(text);
            window.display();
        }
    }
}
};
int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "Animated Text");
    AnimatedText AnimatedText("Hello, world!", sf::seconds(13));
    AnimatedText.show(window);
    return 0;
}