#include <testScene.h>

testScene::testScene() {
  font.loadFromFile("./resources/fonts/KdamThmorPro-Regular.ttf");
  mugshotTexture.loadFromFile("./resources/sprites/pilot.png");
  init();
};

void testScene::init() {
  mugshotTexture.setSmooth(true);
  mugshotSprite.setTexture(mugshotTexture);

  const int GAME_WINDOW_WIDTH = 1200;
  const int GAME_WINDOW_HEIGHT = 700;
  const float TEXTBOX_X = 0.f;
  const float TEXTBOX_Y = GAME_WINDOW_HEIGHT*0.75f;
  const float TEXTBOX_BORDER_THICKNESS = 3;
  const int FONT_SIZE = 24;
  const int FONT_SHADOW_OFFSET = FONT_SIZE * 0.125f;
  const float TEXTBOX_HEIGHT = GAME_WINDOW_HEIGHT*0.25;
  sf::Color grey(128,128,128,255);

  gameText.init(TEXTBOX_X, TEXTBOX_Y, (float)GAME_WINDOW_WIDTH, TEXTBOX_HEIGHT, FONT_SIZE, FONT_SHADOW_OFFSET, TEXTBOX_BORDER_THICKNESS, grey, sf::Color::White, sf::Color::White, sf::Color::Black, &font);
  gameText.setMessage("This is a test of loading fonts in SFML.  The hope is to get a decent scroll rate for this text, as well as automatically make it wrap into the box and eventually script it out. Ideally, this becomes a much more branching conversation system with simple yes/no question answers and beyond.");
  gameText.setMugshot(&mugshotSprite);
};

void testScene::processEvents() {
    
};

void testScene::update(sf::Time deltaTime) {
    gameText.update(deltaTime);
};
      
void testScene::draw(sf::RenderWindow* window) {
    gameText.draw(window);
};

void testScene::end() {
    
};