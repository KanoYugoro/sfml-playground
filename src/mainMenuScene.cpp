#include <mainMenuScene.h>

mainMenuScene::mainMenuScene() {
  titleFont.loadFromFile("./resources/fonts/StintUltraCondensed-Regular.ttf");
  init();
};

void mainMenuScene::init() {
  title.setFont(titleFont);
  title.setString("SFML Game");
  title.setCharacterSize(72);
  title.setFillColor(sf::Color::White);

  selectionOptions.setFont(titleFont);
  selectionOptions.setString("Press Start");
  selectionOptions.setCharacterSize(24);
  selectionOptions.setFillColor(sf::Color::White);
};

void mainMenuScene::processEvents() {

};

void mainMenuScene::update(sf::Time deltaTime) {
  float direction = 1;
  if (alphaDecreasing) {
    direction = -1;
  }
  float adjustment = direction*flashSpeed*deltaTime.asSeconds();
  
  flashAlpha = std::clamp(flashAlpha+adjustment,0.f,255.f);
  selectionOptions.setColor(sf::Color(255,255,255,(sf::Uint8)flashAlpha));

  if (flashAlpha <= 0.f || flashAlpha >= 255.f) {
    alphaDecreasing = !alphaDecreasing;
  }
};
      
void mainMenuScene::draw(sf::RenderWindow* window) {
    sf::Vector2u screenSize = window->getSize();
    title.setPosition(sf::Vector2f((screenSize.x/2)-(title.getLocalBounds().width/2),screenSize.y*0.25f-(title.getLocalBounds().height/2)));
    selectionOptions.setPosition(sf::Vector2f((screenSize.x/2)-(selectionOptions.getLocalBounds().width/2),screenSize.y*0.75f-(selectionOptions.getLocalBounds().height/2)));
    
    window->draw(title);
    window->draw(selectionOptions);
};

void mainMenuScene::end() {
    
};