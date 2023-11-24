#include "GameScene.h"
#include "Game.h"

class mainMenuScene : public GameScene {
    public:
      mainMenuScene();
      void init();
      void processEvents();
      void update(sf::Time deltaTime);
      void draw(sf::RenderWindow* window);
      void end();
    private:
      sf::Font titleFont;
      sf::Text title;
      sf::Text selectionOptions;
      float flashAlpha = 254;
      bool alphaDecreasing = true;
      float flashSpeed = 200;
};