#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

struct buttonSettings{
    int height;
    int width;
    int posX;
    int posY;
    sf::Color color;
    std::string text;
};

constexpr int numberOfButtons = 16;
buttonSettings allSettings[numberOfButtons];
int widthOfButton = 120;
int heightOfButton = 90;
int columns = 4;
int rows = numberOfButtons/columns;
int main()
{
    for(int i = 0; i < numberOfButtons; i++){ //generate settings
        allSettings[i].height = heightOfButton;
        allSettings[i].width = widthOfButton;
        allSettings[i].posX = 0 + (i%columns)*(widthOfButton+1);
        allSettings[i].posY = 0 + (i/columns)*(heightOfButton+1);
        allSettings[i].color = ((i % 4) != 3) ? sf::Color(80,80,80) : sf::Color(255, 140, 40);
        allSettings[i].text = i;
    }
    std::vector<sf::RectangleShape> buttons;
    for(int i = 0; i < numberOfButtons; i ++){ //generate buttons
        sf::RectangleShape button;
        button.setSize(sf::Vector2f(allSettings[i].width, allSettings[i].height));
        button.setPosition(allSettings[i].posX, allSettings[i].posY);
        button.setFillColor(allSettings[i].color);
        buttons.push_back(button);
    }
    sf::RenderWindow mainWindow(sf::VideoMode(widthOfButton*columns+6, heightOfButton*rows+6), "Calculator");


    while(mainWindow.isOpen())
    {
        mainWindow.clear(sf::Color(20,20,20));
        for(int i = 0; i < numberOfButtons; i++){
            mainWindow.draw(buttons[i]);
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
