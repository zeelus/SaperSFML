#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Point.h"

class Board
{

private:
	std::vector<std::vector<Field>> tab;
	sf::RenderWindow *window;
    
    std::vector<int> sortNumbers(int count, int max);
    bool isEndGame = false;
    
    void gameEnd();
    int checkNeighborField(int x, int y);
    std::vector<Point> getNearPoints(int x, int y);
    Field& getFieldFromPoint(const Point& point);
    void clearNearFileds(int x, int y);

    int width;
    int height;
    
public:

	Board(int width, int height, sf::RenderWindow* window);
	~Board(void);

	void update();
	void drow();
    
    void mouseButtonClickedOn(int x, int y);

	void setFieldValue(int xPos, int yPos, Field &field, int nearMain);
};

