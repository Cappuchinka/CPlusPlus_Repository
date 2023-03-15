//
// Created by volch on 15.03.2023.
//

#include "../Headers/Button.h"

Button::Button(int x, int y, int width, int height, bool visible, std::string name) :
        Component(x, y, width, height, visible, name) {}

std::string Button::getInfo(){
    std::string str = "Button have next params: ";
    std::string outstr = str +
                         "\n1)Name: " + name +
                         "\n2)Pos_X: " + std::to_string(x) +
                         "\n3)Pos_Y: " + std::to_string(y) +
                         "\n4)Width: " + std::to_string(width) +
                         "\n5)Height: " + std::to_string(height) +
                         "\n6)Visible: " + std::to_string(visible);
    return outstr;
}

std::string Button::getInfo(int n) {
    std::string str = "Button have next params: ";
    std::string tab(n, '\t');
    std::string outstr = tab + str +
                         "\n" + tab + "1)Name: " + name +
                         "\n" + tab + "2)Pos_X: " + std::to_string(x) +
                         "\n" + tab + "3)Pos_Y: " + std::to_string(y) +
                         "\n" + tab + "4)Width: " + std::to_string(width) +
                         "\n" + tab + "5)Height: " + std::to_string(height) +
                         "\n" + tab + "6)Visible: " + std::to_string(visible);
    return outstr;
}

void Button::setNewXY(int newX, int newY) {
    x = newX;
    y = newY;
}