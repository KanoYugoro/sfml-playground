#include <SFML/Graphics.hpp>
#include <TextBox.h>

int main()
{
    sf::Font font;
    if (!font.loadFromFile("./resources/fonts/KdamThmorPro-Regular.ttf"))
    {
        return 0;
    }

    const int GAME_WINDOW_WIDTH = 1200;
    const int GAME_WINDOW_HEIGHT = 700;
    const float TEXTBOX_X = 0.f;
    const float TEXTBOX_Y = GAME_WINDOW_HEIGHT*0.75f;
    const float TEXTBOX_BORDER_THICKNESS = 5;
    const int FONT_SIZE = 24;
    const int FONT_SHADOW_OFFSET = FONT_SIZE * 0.125f;
    const float TEXTBOX_HEIGHT = GAME_WINDOW_HEIGHT*0.25;
    sf::Color grey(128,128,128,255);

    TextBox gameText(TEXTBOX_X, TEXTBOX_Y, (float)GAME_WINDOW_WIDTH, TEXTBOX_HEIGHT, FONT_SIZE, FONT_SHADOW_OFFSET, 5, grey, sf::Color::White, sf::Color::White, sf::Color::Black, &font);
    gameText.setMessage("This is a test of loading fonts in SFML.");

    sf::RenderWindow window(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), "Game");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        gameText.draw(&window);
        window.display();
    }
}