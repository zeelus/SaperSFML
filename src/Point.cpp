//
// Created by Gilbert Gwizdała on 01.08.2018.
//

#include "Point.h"

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

Point::Point(int x, int y) : x(x), y(y) {}
