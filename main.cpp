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
    Action action{};
};

Action handleClick(int x, int y, const std::vector<ButtonSettings> &buttons);

float calculateInfix(const std::vector<std::string>& infixNotation);

bool isAnOperator(std::string testedValue);

int main()
{
    std::vector<std::string> infixNotation{};
    std::string currentInput = "";
    std::vector<std::string> textContent = {"1", "2", "3", "/", "4", "5", "6", "X", "7", "8", "9", "+", "0", "C", ".",
                                            "-", "=", ""};
    std::vector<std::string> operators = {"/", "*", "+", "-"};
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
    mainWindow.setFramerateLimit(30);
    sf::Clock timer;
    timer.restart();
    bool wasCalculateUsed = false;
    while (mainWindow.isOpen())

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

        float result = 0;
        sf::Event event{};
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
                        buttonsWithText[17].second.setString(currentInput);
                        break;

                    case clear:
                        currentInput = "";
                        infixNotation.clear();
                        buttonsWithText[17].second.setString("");
                        wasCalculateUsed = false;
                        break;

                    case addition:
                    case subtraction:
                    case multiplication:
                    case division:
                        if (!currentInput.empty() || ((currentInput.empty() && !isAnOperator(infixNotation[0])) && infixNotation.size() == 1))
                        {
                            if(!wasCalculateUsed)
                            {
                                infixNotation.push_back(currentInput);
                                result = calculateInfix(infixNotation);
                                infixNotation.push_back(operators[value - division]); //10
                            }else{
                                infixNotation.push_back(operators[value - division]);
                                result = calculateInfix(infixNotation);
                                wasCalculateUsed = false;
                            }
                            buttonsWithText[17].second.setString(std::to_string(result));
                            currentInput = "";
//                            if(infixNotation.size()>2){
//                                result =
//                                infixNotation.clear();
//                                infixNotation.push_back(std::to_string(result));
//                            }

                               for(const auto &i : infixNotation){
                                    std::cout<<i << " ";
                                }
                            std::cout<< std::endl;
                        }
                        break;
                    case calculate:
                        if(!currentInput.empty())
                        {
                            wasCalculateUsed = true;
                            infixNotation.push_back(currentInput);
                            currentInput = "";
                            result = calculateInfix(infixNotation);
                            infixNotation.clear();
                            infixNotation.push_back(std::to_string(result));
                            buttonsWithText[17].second.setString(std::to_string(result));
                        }
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

Action handleClick(int x, int y, const std::vector<ButtonSettings> &buttons)
{
    for (const auto & button : buttons)
    {
        if (button.posX < x && (button.posX + button.width) > x)
        {
            if (button.posY < y && (button.posY + button.height) > y)
            {
                return button.action;
            }
        }
    }
    return none;
}

float calculateInfix(const std::vector<std::string>& infixNotation)
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
    for(int i = operators.size()-1; i >= 0; i--){
        prefixNotation.push_back(operators[i]);
    }
    std::stack<float> result;
    for (auto &i : prefixNotation)
    {
        if (i == "+" || i == "/" || i == "*" || i == "-")
        {
            float numberA = result.top();
            result.pop();
            if (!result.empty())
            {
                float numberB = result.top();
                result.pop();
                if (i == "+")
                {
                    result.push(numberB + numberA);
                } else if (i == "-")
                {
                    result.push(numberB - numberA);
                } else if (i == "*")
                {
                    result.push(numberB * numberA);
                } else
                {
                    result.push(numberB / numberA);
                }
            } else
            {
                return numberA;
            }
        } else
        {
            result.push(std::stof(i));
        }
    }
    std::cout << "prefixNotation: ";
    for(const auto &i : prefixNotation){
        std::cout<<i;
        std::cout<< " ";
    }
    std::cout <<std::endl;
    std::cout << result.top() << std::endl;
    return result.top();
}
inline bool isAnOperator(std::string testedValue){
    return testedValue == "+" || testedValue == "/" || testedValue == "-" || testedValue == "*";
}