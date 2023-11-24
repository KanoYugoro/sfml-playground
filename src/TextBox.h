#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
    public:
      float x, y, w, h, charsPerSecond;
      int fontSize, fontShadowOffset, borderThickness;
      sf::Color backgroundColor;
      sf::Color textColor;
      sf::Color borderColor;
      sf::Color textShadowColor;
      sf::Font* font;

      TextBox();
      void init(float _x, float _y, float _w, float _h, int _fontSize, int _fontShadowOffset, int _borderThickness, sf::Color _backgroundColor, sf::Color _borderColor, sf::Color _textColor, sf::Color _textShadowColor, sf::Font* _font);
      void update(sf::Time deltaTime);
      void draw(sf::RenderWindow* window);
      void setMessage(std::string newMessage);
      void setDisplayMessage(std::string newDisplayMessage);
      void setMugshot(sf::Sprite* _mugshot);
    private:
      sf::CircleShape finishedIndicator;
      float wiggleAmplitude = 8.0f;
      float wiggleSpeed = 3.f;

      std::string autoFormat(std::string input);
      bool initialized;

      sf::Time accumulatedTime = sf::Time::Zero;
      bool finished = false;
      std::string message;
      std::string displayedMessage;
      float maxTextWidth = 976;
      float maxTextLines = 4;

      sf::RectangleShape background;
      sf::RectangleShape mugBackground;
      sf::Text text;
      sf::Text text_shadow;
      sf::Text noMugText;
      bool hasMugshot = false;
      float mugBackgroundHeight;
      float mugBackgroundWidth;
      float mugBackgroundX;
      float mugBackgroundY;
      sf::Sprite* mugshot;
};