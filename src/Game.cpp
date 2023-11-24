#include <Game.h>

Game::Game() {
  init();
  setScene(&mainMenu);
};

void Game::init() {

};

void Game::processEvents() {
    currentScene->processEvents();
};

void Game::update(sf::Time deltaTime) {
    currentScene->update(deltaTime);
};
      
void Game::draw(sf::RenderWindow* window) {
    currentScene->draw(window);
};

void Game::setScene(GameScene* newScene) {
    currentScene = newScene;
};