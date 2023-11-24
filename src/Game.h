#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "mainMenuScene.h"

class Game {
    public:
      Game();
      void init();
      void processEvents();
      void update(sf::Time deltaTime);
      void draw(sf::RenderWindow* window);
      void setScene(GameScene* newScene);
    private:
      GameScene* currentScene;
      mainMenuScene mainMenu;
};