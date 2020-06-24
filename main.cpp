#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using TextButton = std::pair<sf::RectangleShape, std::string>;

struct ButtonSettings{
    int height{};
    int width{};
    int posX{};
    int posY{};
    sf::Color color;
    std::string text;
};
std::vector<std::string> textContent = {"1","2","3","/", "4","5","6","X", "7","8","9","+","0", "C",".","-", "="};
constexpr int numberOfButtons = 16;
std::vector<ButtonSettings> buttonSettings;
int widthOfButton = 120;
int heightOfButton = 90;
int columns = 4;
int rows = numberOfButtons/columns;
int main()
{
    for(int i = 0; i < numberOfButtons; i++){ //generate settings
        ButtonSettings settings;
        settings.height = heightOfButton;
        settings.width = widthOfButton;
        settings.posX = 0 + (i%columns)*(widthOfButton+1);
        settings.posY = 0 + (i/columns)*(heightOfButton+1);
        settings.color = ((i % 4) != 3) ? sf::Color(80,80,80) : sf::Color(255, 140, 40);
        settings.text = textContent[i];
        buttonSettings.push_back(settings);
    }
    std::vector<TextButton> buttonsWithText{};
    for(int i = 0; i < numberOfButtons; i ++){ //generate buttons
        sf::RectangleShape button;
        button.setSize(sf::Vector2f(buttonSettings[i].width, buttonSettings[i].height));
        button.setPosition(buttonSettings[i].posX, buttonSettings[i].posY);
        button.setFillColor(buttonSettings[i].color);
        TextButton textButton{button,buttonSettings[i].text};
        buttonsWithText.push_back(textButton);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(widthOfButton*columns+6, heightOfButton*rows+6), "Calculator");


    while(mainWindow.isOpen())
    {
        sf::Font font;
        mainWindow.clear(sf::Color(20,20,20));
        for(int i = 0; i < numberOfButtons; i++){
            mainWindow.draw(buttonsWithText[i].first);
            sf::Font font;
            sf::Text text;
            font.loadFromFile("Arial.ttf");
            text.setFont(font);
            text.setCharacterSize(30);
            text.setPosition(buttonsWithText[i].first.getPosition().x+45, buttonsWithText[i].first.getPosition().y+30);
            text.setFillColor(sf::Color(255,255,255));
            text.setString(buttonsWithText[i].second);
            mainWindow.draw(text);
        }
        mainWindow.display();
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }
    }

}
