//
// Created by volch on 15.03.2023.
//

#include "../Headers/Line.h"

Line::Line(int x1, int y1, int x2, int y2, bool visible, std::string name) : x1{x1},
                                                                             y1{y1},
                                                                             x2{x2},
                                                                             y2{y2},
                                                                             Component(visible, name) {}

void Line::newCoordinates(int newX1, int newY1, int newX2, int newY2) {
    x1 = newX1;
    y1 = newY1;
    x2 = newX2;
    y2 = newY2;
}

std::string Line::getInfo() {
    std::string str = "Line have next params:";
    std::string outstr = str +
                         "\n1)Name: " + name +
                         "\n2)\tx1: " + std::to_string(x1) +
                         "\n  \ty1: " + std::to_string(y1) +
                         "\n3)\tx2: " + std::to_string(x2) +
                         "\n  \ty2 : " + std::to_string(y2);
    return outstr;
}
std::string Line::getInfo(int n) {
    std::string tab(n, '\t');
    std::string str = "Line have next params:";
    std::string outstr = tab+str +
                         "\n" + tab + "1)Name: " + name +
                         "\n" + tab + "2)x1: " + std::to_string(x1) +
                         "\n" + tab + "  y1: " + std::to_string(y1) +
                         "\n" + tab + "3)x2: " + std::to_string(x2) +
                         "\n" + tab + "  y2 : " + std::to_string(y2);
    return  outstr;
}

void Line::setNewXY(int newX, int newY) {
    x = newX;
    y = newY;
}
