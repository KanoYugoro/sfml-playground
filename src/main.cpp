#include <SFML/Graphics.hpp>
#include <Game.h>

int main()
{
    const int GAME_WINDOW_WIDTH = 1200;
    const int GAME_WINDOW_HEIGHT = 700;

    Game game;

    // Delta Time setup
    sf::Clock gameClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

    sf::RenderWindow window(sf::VideoMode(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT), "Game");
    
    while (window.isOpen())
    {
        game.processEvents();
        timeSinceLastUpdate = gameClock.restart();

        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            game.processEvents();
            game.update(TIME_PER_FRAME);
        }

        game.update(timeSinceLastUpdate);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render
        window.clear();
        game.draw(&window);
        window.display();
    }
}
