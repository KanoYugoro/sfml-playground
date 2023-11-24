#include "GameScene.h"
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
};