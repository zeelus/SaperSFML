#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Field.h"

int main(int argc, const char * argv[]) {

    sf::RenderWindow window(sf::VideoMode(600, 800), "SFML Saper");
    Board board(15, 12, &window);
    Field::loadTextures();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    board.mouseButtonClickedOn(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        board.update();
        window.clear();
        board.drow();
        window.display();
    }

    return 0;

}