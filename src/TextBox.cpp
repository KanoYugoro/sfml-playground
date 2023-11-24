#include <TextBox.h>

TextBox::TextBox() {
    initialized = false;
}

void TextBox::init(float _x, float _y, float _w, float _h, int _fontSize, int _fontShadowOffset, int _borderThickness, sf::Color _backgroundColor, sf::Color _borderColor, sf::Color _textColor, sf::Color _textShadowColor, sf::Font* _font) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    charsPerSecond = 50.f;
    fontSize = _fontSize;
    fontShadowOffset = _fontShadowOffset;
    borderThickness = _borderThickness;
    backgroundColor = _backgroundColor;
    borderColor = _borderColor;
    textColor = _textColor;
    textShadowColor = _textShadowColor;
    font = _font;
    message = "";
    displayedMessage = "";

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

    text.setFont(*font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);
    text.setPosition(mugBackgroundX+mugBackgroundWidth+(fontSize*.5f), y+(fontSize*.5f));

    text_shadow.setFont(*font);
    text_shadow.setString(message);
    text_shadow.setCharacterSize(fontSize);
    text_shadow.setFillColor(textShadowColor);
    text_shadow.setPosition(mugBackgroundX+mugBackgroundWidth+(fontSize*.5f)+fontShadowOffset, y+(fontSize*.5f)+fontShadowOffset);

    noMugText.setFont(*font);
    noMugText.setString("    NO\nSIGNAL");
    noMugText.setCharacterSize(fontSize);
    noMugText.setFillColor(textColor);
    noMugText.setPosition(x+(mugBackgroundWidth*.33f), y+(mugBackgroundHeight*.33f));

    finishedIndicator = sf::CircleShape(18.f,3);
    finishedIndicator.rotate(180.f);
    finishedIndicator.setPosition(w-18.f,y+h-18.f);
    initialized = true;
}

void TextBox::update(sf::Time deltaTime) {
    if (initialized) {
        if (finished) {
            accumulatedTime = accumulatedTime + wiggleSpeed*deltaTime;
            sf::Vector2f temporaryPosition = finishedIndicator.getPosition();
            temporaryPosition.y = y + h - 18.f + wiggleAmplitude*sinf(accumulatedTime.asSeconds());
            finishedIndicator.setPosition(temporaryPosition);
            if (accumulatedTime.asSeconds() >= 3.14f) {
                accumulatedTime = sf::Time::Zero;
            }
        } else {
            accumulatedTime = accumulatedTime + deltaTime;
            if (accumulatedTime.asSeconds() > (1.0f/charsPerSecond)) {
                accumulatedTime = sf::Time::Zero;
                int charsToDisplay = displayedMessage.length() + 1;
                setDisplayMessage(message.substr(0,charsToDisplay));

                finished = (charsToDisplay >= message.length());
            }
        }
    }
}

void TextBox::draw(sf::RenderWindow* window) {
    if (initialized) {
        window->draw(background);
        window->draw(mugBackground);
        if (hasMugshot) {
            window->draw(*mugshot);
        } else {
            window->draw(noMugText);
        }
        window->draw(text_shadow);
        window->draw(text);

        if (finished) {
            window->draw(finishedIndicator);
        }
    }
}

void TextBox::setMessage(std::string newMessage) {
    if (initialized) {
        message = newMessage;
        displayedMessage = "";
        finished = false;
        accumulatedTime = sf::Time::Zero;

        //Hack to insert autonewlines based on character widths.
        message = autoFormat(message);
        //End hack

        text_shadow.setString(displayedMessage);
        text.setString(displayedMessage);
    }
}

std::string TextBox::autoFormat(std::string input) {
    text.setString(input);
    float totalStrWidth = text.getLocalBounds().width;
    float strWidth = 0;
    int index = 1;
    int lastEmptyIndex = 1;
    while (totalStrWidth > maxTextWidth) {
        while (strWidth < maxTextWidth) {
            text.setString(input.substr(0,index));
            strWidth = text.getLocalBounds().width;
            if ((input[index]) == ' ') {
                lastEmptyIndex = index;
            }

            index = index + 1;
        }
        input.erase(lastEmptyIndex,1);
        input.insert(lastEmptyIndex, "\n");
        text.setString(input);
        totalStrWidth = text.getLocalBounds().width;
        index = index + 1;
        text.setString(input.substr(0,index));
        strWidth = text.getLocalBounds().width;
    }

    return input;
}

void TextBox::setDisplayMessage(std::string newDisplayMessage) {
    displayedMessage = newDisplayMessage;
    text_shadow.setString(displayedMessage);
    text.setString(displayedMessage);
}

void TextBox::setMugshot(sf::Sprite* _mugshot) {
    if (initialized) {
        hasMugshot = true;
        mugshot = _mugshot;
        mugshot->setPosition(x+(borderThickness*3),y+(borderThickness*3));

        sf::Vector2u mugSize = mugshot->getTexture()->getSize();
        float scaleFactor = (mugBackgroundWidth / mugSize.x);

        mugshot->setScale(sf::Vector2f(scaleFactor,scaleFactor));
    }
}