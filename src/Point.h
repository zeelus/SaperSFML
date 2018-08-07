//
// Created by Gilbert Gwizdała on 01.08.2018.
//

#ifndef SAPER_POINT_H
#define SAPER_POINT_H


class Point {

private:
    int x;
    int y;
public:
    int getX() const;
    int getY() const;

    Point(int x, int y);

};


#endif //SAPER_POINT_H
