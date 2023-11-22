#include <TextBox.h>

TextBox::TextBox(float _x, float _y, float _w, float _h, int _fontSize, int _fontShadowOffset, int _borderThickness, sf::Color _backgroundColor, sf::Color _borderColor, sf::Color _textColor, sf::Color _textShadowColor, sf::Font* _font) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    fontSize = _fontSize;
    fontShadowOffset = _fontShadowOffset;
    borderThickness = _borderThickness;
    backgroundColor = _backgroundColor;
    borderColor = _borderColor;
    textColor = _textColor;
    textShadowColor = _textShadowColor;
    font = _font;
    message = "";

    background = sf::RectangleShape(sf::Vector2f(w-(borderThickness*2), h-(borderThickness*2)));
    background.setPosition(x+borderThickness, y+borderThickness);
    background.setFillColor(backgroundColor);
    background.setOutlineThickness(borderThickness);
    background.setOutlineColor(borderColor);

    text = sf::Text();
    text.setFont(*font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);
    text.setPosition(x+fontSize, y+fontSize);

    text_shadow = sf::Text();
    text_shadow.setFont(*font);
    text_shadow.setString(message);
    text_shadow.setCharacterSize(fontSize);
    text_shadow.setFillColor(textShadowColor);
    text_shadow.setPosition(x+fontSize+fontShadowOffset, y+fontSize+fontShadowOffset);
}

void TextBox::draw(sf::RenderWindow* window) {
    window->draw(background);
    window->draw(text_shadow);
    window->draw(text);
}

void TextBox::setMessage(std::string newMessage) {
    message = newMessage;
    text_shadow.setString(message);
    text.setString(message);
}