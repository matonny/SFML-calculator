#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using TextButton = std::pair<sf::RectangleShape, sf::Text>;

struct ButtonSettings
{
    int height{};
    int width{};
    int posX{};
    int posY{};
    sf::Color color;
    std::string text;
};


void handleClick(int x, int y);

int main()
{
    std::vector<std::string> textContent = {"1", "2", "3", "/", "4", "5", "6", "X", "7", "8", "9", "+", "0", "C", ".",
                                            "-", "="};
    constexpr int numberOfButtons = 18;
    std::vector<ButtonSettings> buttonSettings;
    int widthOfButton = 120;
    int heightOfButton = 90;
    int columns = 4;
    int rows = numberOfButtons / columns + 1;

    for (int i = 0; i < numberOfButtons; i++)
    { //generate settings
        ButtonSettings settings;
        settings.height = heightOfButton;
        settings.width = widthOfButton;
        settings.posX = 0 + (i % columns) * (widthOfButton + 1);
        settings.posY = 0 + (i / columns) * (heightOfButton + 1);
        settings.color = ((i % 4) != 3) ? sf::Color(80, 80, 80) : sf::Color(255, 140, 40);
        settings.text = textContent[i];
        buttonSettings.push_back(settings);
    }
    buttonSettings[numberOfButtons - 1].width = widthOfButton * 3 + 2;
    std::vector<TextButton> buttonsWithText{};
    for (int i = 0; i < numberOfButtons; i++)
    { //generate buttons
        sf::RectangleShape button;
        button.setSize(sf::Vector2f(buttonSettings[i].width, buttonSettings[i].height));
        button.setPosition(buttonSettings[i].posX, buttonSettings[i].posY);
        button.setFillColor(buttonSettings[i].color);
        sf::Font font;
        font.loadFromFile("Arial.ttf");
        sf::Text text = sf::Text(buttonSettings[i].text, font);
        text.setPosition(buttonSettings[i].posX+50, buttonSettings[i].posY+25);
        text.setFillColor(sf::Color(255,255,255));
        TextButton textButton{button, text};
        buttonsWithText.push_back(textButton);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(widthOfButton * columns + 6, heightOfButton * rows + 6), "Calculator");


    while (mainWindow.isOpen())
    {
        sf::Font font;
        mainWindow.clear(sf::Color(20, 20, 20));
        for (int i = 0; i < numberOfButtons; i++)
        {
            mainWindow.draw(buttonsWithText[i].first);
            mainWindow.draw(buttonsWithText[i].second);
        }
        mainWindow.display();
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                handleClick(event.mouseButton.x, event.mouseButton.y);
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }
    }

}

void handleClick(int x, int y)
{

}