#include "Board.h"
#include <iostream>

Board::Board(int width, int height, sf::RenderWindow* window)
{
	this->window = window;
	this->height = height;
	this->width = width;
    
	for(int i = 0; i < height; i++) {
		this->tab.emplace_back();
		auto &v = tab.back();
		for(int j = 0; j < width; j++) {
			v.emplace_back();
		}
	}
    
    auto findNumbers = this->sortNumbers(20, (height * width) - 1);
    
    for(auto num: findNumbers) {
        
        int col = num / width;
        int row = num % width;
    
        this->tab[col][row].isMine = true;
        
    }
}

std::vector<int> Board::sortNumbers(int count, int max) {
    std::vector<int> findNumbers;
    
    for(int i = 0; i < count; i++ ) {
        std::srand((unsigned int) std::time(nullptr));
        bool find = true;
        int randNum = -1;
        while(find) {
            randNum = rand() % max;
            find = false;
            for(auto &num : findNumbers) {
                if(num == randNum){
                    find = true;
                    continue;
                }
            }
        }
        
        findNumbers.push_back(randNum);
    }
    
    return findNumbers;
}


Board::~Board()
{
    
}

void Board::drow()
{
	for(int i = 0; i < this->tab.size(); i++) {
		for(int j = 0; j < this->tab[i].size(); j++) {
			auto& filed = tab[i][j];
            sf::Sprite sprite;
            sprite.setTexture(*(filed.getTexture()));
            sprite.setPosition(i*50, j*50);
            sprite.scale(0.125f, 0.125f);
            this->window->draw(sprite);
		}
	}
}

void Board::update() {

}

void Board::mouseButtonClickedOn(int x, int y) {
    
    if( this->isEndGame ) return;
    
    int xPos = x / 50;
    int yPos = y / 50;
    
    auto &field = this->tab[xPos][yPos];

    if(field.getType() != FieldType::hide)
        return;
    
    if(field.isMine) {
        this->gameEnd();
        return;
    }

    int nearMain = checkNeighborField(xPos, yPos);

    setFieldValue(xPos, yPos, field, nearMain);
}

void Board::setFieldValue(int xPos, int yPos, Field &field, int nearMain) {
    switch (nearMain) {
        case 0:
            clearNearFileds(xPos, yPos);
            break;
        case 1:
            field.changeTypeTo(FieldType::number1);
            break;
        case 2:
            field.changeTypeTo(FieldType::number2);
            break;
        case 3:
            field.changeTypeTo(FieldType::number3);
            break;
        case 4:
            field.changeTypeTo(FieldType::number4);
            break;
        case 5:
            field.changeTypeTo(FieldType::number5);
            break;
        case 6:
            field.changeTypeTo(FieldType::number6);
            break;
        case 7:
            field.changeTypeTo(FieldType::number7);
            break;
        case 8:
            field.changeTypeTo(FieldType::number8);
            break;
        default:
            break;
    }
}

void Board::gameEnd() { 
    this->isEndGame = true;
    
    for(int i = 0; i < this->tab.size(); i++) {
        for(int j = 0; j < this->tab[i].size(); j++) {
            auto& field = this->tab[i][j];
            if(field.isMine) {
                field.changeTypeTo(FieldType::mine);
            }
        }
    }
}

int Board::checkNeighborField(int x, int y) {

    int nearMain = 0;

    for(auto& point: getNearPoints(x, y)) {
        auto& field = getFieldFromPoint(point);
        if(field.isMine)
            nearMain++;
    }

    return nearMain;
}

std::vector<Point> Board::getNearPoints(int x, int y) {
    auto points = std::vector<Point>();

    for(int zx = (x - 1); zx <= (x + 1); zx++) {
        for (int zy = (y - 1); zy <= (y + 1); zy++) {

            if((zx < 0) || (zy < 0) || (zx >= this->height) || (zy >= this->width)) {
                continue;
            }
            points.push_back(Point(zx, zy));

        }
    }
    return points;
}

Field& Board::getFieldFromPoint(const Point &point) {
    return this->tab[point.getX()][point.getY()];
}

void Board::clearNearFileds(int x, int y) {

    auto& field = getFieldFromPoint(Point(x, y));

    field.changeTypeTo(FieldType::empty);

    for(auto& nearPoint: getNearPoints(x, y)) {
        auto& field = getFieldFromPoint(nearPoint);
        if(!field.isMine && field.getType() == FieldType::hide) {

            int n = checkNeighborField(x, y);
            if(n == 0) {
                clearNearFileds(nearPoint.getX(), nearPoint.getY());
            }
        }

    }

    int nearMine = checkNeighborField(x, y);
    if(nearMine != 0 ){
        setFieldValue(x, y, field, nearMine);
    }


}

