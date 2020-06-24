#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using TextButton = std::pair<sf::RectangleShape, sf::Text>;
enum Action {
    none = -1,
    figure0,
    figure1,
    figure2,
    figure3,
    figure4,
    figure5,
    figure6,
    figure7,
    figure8,
    figure9,
    division,
    multiplication,
    addition,
    subtraction,
    calculate,
    fraction,
    clear
};
struct ButtonSettings
{
    int height{};
    int width{};
    int posX{};
    int posY{};
    sf::Color color;
    std::string text;
    Action action;
};

Action handleClick(int x, int y, const std::vector<ButtonSettings> &buttons);


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
    ButtonSettings settings;
    for (int i = 0; i < numberOfButtons; i++)
    { //generate settings

        settings.height = heightOfButton;
        settings.width = widthOfButton;
        settings.posX = 0 + (i % columns) * (widthOfButton + 1);
        settings.posY = 0 + (i / columns) * (heightOfButton + 1);
        settings.color = ((i % 4) != 3) ? sf::Color(80, 80, 80) : sf::Color(255, 140, 40);
        settings.text = textContent[i];
        buttonSettings.push_back(settings);
    }
    buttonSettings[0].action = figure1;
    buttonSettings[1].action = figure2;
    buttonSettings[2].action = figure3;
    buttonSettings[3].action = division;
    buttonSettings[4].action = figure4;
    buttonSettings[5].action = figure5;
    buttonSettings[6].action = figure6;
    buttonSettings[7].action = multiplication;
    buttonSettings[8].action = figure7;
    buttonSettings[9].action = figure8;
    buttonSettings[10].action = figure9;
    buttonSettings[11].action = addition;
    buttonSettings[12].action = figure0;
    buttonSettings[13].action = clear;
    buttonSettings[14].action = fraction;
    buttonSettings[15].action = subtraction;
    buttonSettings[16].action = calculate;

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
        sf::Text text = sf::Text();
        text.setString(buttonSettings[i].text);
        text.setPosition(buttonSettings[i].posX+50, buttonSettings[i].posY+25);
        text.setFillColor(sf::Color(255,255,255));
        TextButton textButton{button, text};
        buttonsWithText.push_back(textButton);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(widthOfButton * columns + 6, heightOfButton * rows + 6), "Calculator");

    sf::Font font;
    font.loadFromFile("Arial.ttf");
    while (mainWindow.isOpen())
    {

        mainWindow.clear(sf::Color(20, 20, 20));
        for (int i = 0; i < numberOfButtons; i++)
        {
            mainWindow.draw(buttonsWithText[i].first);
            buttonsWithText[i].second.setFont(font);
            mainWindow.draw(buttonsWithText[i].second);
        }
        mainWindow.display();
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                Action result = handleClick(event.mouseButton.x, event.mouseButton.y, buttonSettings);
                switch (result){
                    case figure7:
                        std::cout << "klik na 7 pyk" << std::endl;
                        break;
                    default:
                        break;
                }
            }
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                mainWindow.close();
        }
    }

}

Action handleClick(int x, int y, const std::vector<ButtonSettings> &buttons)
{
    for(int i = 0; i < buttons.size(); i++){
        if(buttons[i].posX < x && (buttons[i].posX+buttons[i].width) > x){
            if(buttons[i].posY < y && (buttons[i].posY+buttons[i].height) > y){
                return buttons[i].action;
            }
        }
    }
    return none;
}