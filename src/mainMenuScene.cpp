#include <mainMenuScene.h>

mainMenuScene::mainMenuScene() {
  titleFont.loadFromFile("./resources/fonts/StintUltraCondensed-Regular.ttf");
  init();
};

void mainMenuScene::init() {
  title = sf::Text();
  title.setFont(titleFont);
  title.setString("SFML Game");
  title.setCharacterSize(72);
  title.setFillColor(sf::Color::White);
};

void mainMenuScene::processEvents() {
    
};

void mainMenuScene::update(sf::Time deltaTime) {
    
};
      
void mainMenuScene::draw(sf::RenderWindow* window) {
    sf::Vector2u screenSize = window->getSize();
    title.setPosition(sf::Vector2f((screenSize.x/2)-(title.getLocalBounds().width/2),screenSize.y*0.25f));
    window->draw(title);
};

void mainMenuScene::end() {
    
};