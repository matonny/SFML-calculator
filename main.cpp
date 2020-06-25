#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stack>

using TextButton = std::pair<sf::RectangleShape, sf::Text>;
enum Action
{
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

int calculateInfix(std::vector<std::string> infixNotation);


int main()
{
    std::vector<std::string> infixNotation{};
    std::string currentInput = "";
    std::vector<std::string> textContent = {"1", "2", "3", "/", "4", "5", "6", "X", "7", "8", "9", "+", "0", "C", ".",
                                            "-", "=", "123"};
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
        settings.posY = 0 + (i / columns) * (heightOfButton + 2);
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
        sf::Text text = sf::Text();
        text.setString(buttonSettings[i].text);
        text.setPosition(buttonSettings[i].posX + 50, buttonSettings[i].posY + 25);
        text.setFillColor(sf::Color(255, 255, 255));
        TextButton textButton{button, text};
        buttonsWithText.push_back(textButton);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(widthOfButton * columns + 6, heightOfButton * rows + 6), "Calculator");

    sf::Font font;
    font.loadFromFile("/Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug/Arial.ttf");
    sf::Clock timer;
    timer.restart();
    while (mainWindow.isOpen())
    {
        if (timer.getElapsedTime().asSeconds() > (1.0 / 30.0))
        {
            timer.restart();
            mainWindow.clear(sf::Color(20, 20, 20));
            for (int i = 0; i < numberOfButtons; i++)
            {
                mainWindow.draw(buttonsWithText[i].first);
                buttonsWithText[i].second.setFont(font);
                mainWindow.draw(buttonsWithText[i].second);
            }
            mainWindow.display();

            int result = 0;
            sf::Event event;
            while (mainWindow.pollEvent(event))
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    Action value = handleClick(event.mouseButton.x, event.mouseButton.y, buttonSettings);
                    switch (value)
                    {
                        case figure0:
                        case figure1:
                        case figure2:
                        case figure3:
                        case figure4:
                        case figure5:
                        case figure6:
                        case figure7:
                        case figure8:
                        case figure9:
                            currentInput += std::to_string(value);
                            std::cout << currentInput << std::endl;
                            buttonsWithText[17].second.setString(currentInput);
                            break;

                        case clear:
                            currentInput = "";
                            infixNotation.clear();
                            break;

                        case addition:
                            std::cout << "dodawanko" << std::endl;
                            if (currentInput != "")
                            {
                                infixNotation.push_back(currentInput);
                                infixNotation.push_back("+");
                                currentInput = "";
                                buttonsWithText[17].second.setString(std::to_string(result));
                            }
                            break;
                        case subtraction:
                            std::cout << "minusik" << std::endl;
                            infixNotation.push_back(currentInput);
                            infixNotation.push_back("-");
                            currentInput = "";
                            break;
                        case multiplication:
                            std::cout << "mnozonko" << std::endl;
                            infixNotation.push_back(currentInput);
                            infixNotation.push_back("*");
                            currentInput = "";
                            break;
                        case division:
                            std::cout << "dzielonko" << std::endl;
                            infixNotation.push_back(currentInput);
                            infixNotation.push_back("/");
                            currentInput = "";
                            break;
                        case calculate:
                            std::cout << "liczonko" << std::endl;
                            infixNotation.push_back(currentInput);
                            currentInput = "";
                            result = calculateInfix(infixNotation);
                            break;

                        default:
                            buttonSettings[13].text = currentInput;
                            break;
                    }

                }
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    mainWindow.close();
            }
        }
    }

}

Action handleClick(int x, int y, const std::vector<ButtonSettings> &buttons)
{
    for (int i = 0; i < buttons.size(); i++)
    {
        if (buttons[i].posX < x && (buttons[i].posX + buttons[i].width) > x)
        {
            if (buttons[i].posY < y && (buttons[i].posY + buttons[i].height) > y)
            {
                return buttons[i].action;
            }
        }
    }
    return none;
}

int calculateInfix(std::vector<std::string> infixNotation)
{
    std::vector<std::string> prefixNotation{};
    std::vector<std::string> numbers{};
    std::vector<std::string> operators{};
    for (auto &i : infixNotation)
    {
        if (i == "+" || i == "/" || i == "*" || i == "-")
        {
            operators.push_back(i);
        } else
        {
            numbers.push_back(i);
        }
    }
    prefixNotation = numbers;
    for (const auto &i : operators)
    {
        prefixNotation.push_back(i);
    }
    std::stack<float> result;
    for(auto &i : prefixNotation){
        if (i == "+" || i == "/" || i == "*" || i == "-")
        {
            float numberA = result.top();
            result.pop();
            float numberB = result.top();
            result.pop();
            if(i == "+"){
                result.push(numberB+numberA);
            }
            else if(i == "-"){
                result.push(numberB-numberA);
            }
            else if(i == "*"){
                result.push(numberB*numberA);
            }
            else{
                result.push(numberB/numberA);
            }
        } else
        {
            result.push(std::stof(i));
        }
    }
    std::cout<<result.top()<<std::endl;
    return result.top();

}