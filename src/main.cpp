#include <SFML/Graphics.hpp>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("./resources/fonts/KdamThmorPro-Regular.ttf"))
    {
        return 0;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("This is a test of loading fonts in SFML.");
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::White);
    text.setPosition(100.f, 300.f);
    
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);



    while (window.isOpen())
    {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear();
    window.draw(shape);
    window.draw(text);
    window.display();
    }
}