#include "GameScene.h"
#include "TextBox.h"
class testScene : public GameScene {
    public:
      testScene();
      void init();
      void processEvents();
      void update(sf::Time deltaTime);
      void draw(sf::RenderWindow* window);
      void end();
    private:
      sf::Font font;
      sf::Texture mugshotTexture;
      sf::Sprite mugshotSprite;
      TextBox gameText;
};