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

    mugBackgroundHeight = h-(borderThickness*6);
    mugBackgroundWidth = mugBackgroundHeight;
    mugBackgroundX = x+(borderThickness*3);
    mugBackgroundY = y+(borderThickness*3);

    mugBackground = sf::RectangleShape(sf::Vector2f(mugBackgroundHeight, mugBackgroundWidth));
    mugBackground.setPosition(mugBackgroundX, mugBackgroundY);
    mugBackground.setFillColor(backgroundColor);
    mugBackground.setOutlineThickness(borderThickness);
    mugBackground.setOutlineColor(borderColor);

    text = sf::Text();
    text.setFont(*font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);
    text.setPosition(mugBackgroundX+mugBackgroundWidth+(fontSize*.5f), y+(fontSize*.5f));

    text_shadow = sf::Text();
    text_shadow.setFont(*font);
    text_shadow.setString(message);
    text_shadow.setCharacterSize(fontSize);
    text_shadow.setFillColor(textShadowColor);
    text_shadow.setPosition(mugBackgroundX+mugBackgroundWidth+(fontSize*.5f)+fontShadowOffset, y+(fontSize*.5f)+fontShadowOffset);

    noMugText = sf::Text();
    noMugText.setFont(*font);
    noMugText.setString("    NO\nSIGNAL");
    noMugText.setCharacterSize(fontSize);
    noMugText.setFillColor(textColor);
    noMugText.setPosition(x+(mugBackgroundWidth*.33f), y+(mugBackgroundHeight*.33f));
}

void TextBox::draw(sf::RenderWindow* window) {
    window->draw(background);
    window->draw(mugBackground);
    if (hasMugshot) {
        window->draw(*mugshot);
    } else {
        window->draw(noMugText);
    }
    window->draw(text_shadow);
    window->draw(text);
}

void TextBox::setMessage(std::string newMessage) {
    message = newMessage;
    text_shadow.setString(message);
    text.setString(message);
}

void TextBox::setMugshot(sf::Sprite* _mugshot) {
    hasMugshot = true;
    mugshot = _mugshot;
    mugshot->setPosition(x+(borderThickness*3),y+(borderThickness*3));

    sf::Vector2u mugSize = mugshot->getTexture()->getSize();
    float scaleFactor = (mugBackgroundWidth / mugSize.x);

    mugshot->setScale(sf::Vector2f(scaleFactor,scaleFactor));
}