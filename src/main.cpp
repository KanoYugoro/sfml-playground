#include <SFML/Graphics.hpp>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("./resources/fonts/KdamThmorPro-Regular.ttf"))
    {
        return 0;
    }
    const int GAME_WINDOW_WIDTH = 1200;
    const int GAME_WINDOW_HEIGHT = 700;
    const float TEXTBOX_X = 0;
    const float TEXTBOX_Y = GAME_WINDOW_HEIGHT*0.75f;
    const float TEXTBOX_BORDER_THICKNESS = 5;
    const int FONT_SIZE = 16;
    const int FONT_SHADOW_OFFSET = FONT_SIZE * 0.125f;

    sf::Color grey(128,128,128,255);

    sf::RenderWindow window(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), "Game");

    sf::RectangleShape shape(sf::Vector2f(GAME_WINDOW_WIDTH-(TEXTBOX_BORDER_THICKNESS*2), (GAME_WINDOW_HEIGHT*.25f)-(TEXTBOX_BORDER_THICKNESS*2)));
    shape.setPosition(TEXTBOX_X+TEXTBOX_BORDER_THICKNESS, TEXTBOX_Y+TEXTBOX_BORDER_THICKNESS);
    shape.setFillColor(grey);
    shape.setOutlineThickness(TEXTBOX_BORDER_THICKNESS);
    shape.setOutlineColor(sf::Color::White);

    sf::Text text;
    text.setFont(font);
    text.setString("This is a test of loading fonts in SFML.");
    text.setCharacterSize(FONT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setPosition(TEXTBOX_X+FONT_SIZE, TEXTBOX_Y+FONT_SIZE);

    sf::Text text_shadow;
    text_shadow.setFont(font);
    text_shadow.setString("This is a test of loading fonts in SFML.");
    text_shadow.setCharacterSize(FONT_SIZE);
    text_shadow.setFillColor(sf::Color::Black);
    text_shadow.setPosition(TEXTBOX_X+FONT_SIZE+FONT_SHADOW_OFFSET, TEXTBOX_Y+FONT_SIZE+FONT_SHADOW_OFFSET);
    
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
    window.draw(text_shadow);
    window.draw(text);
    window.display();
    }
}