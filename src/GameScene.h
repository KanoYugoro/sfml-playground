#pragma once
#include <SFML/Graphics.hpp>
class GameScene {
    public:
      virtual void init() = 0;
      virtual void processEvents() = 0;
      virtual void update(sf::Time deltaTime) = 0;
      virtual void draw(sf::RenderWindow* window) = 0;
      virtual void end() = 0;
    private:
};