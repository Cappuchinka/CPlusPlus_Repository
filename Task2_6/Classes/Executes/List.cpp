//
// Created by volch on 15.03.2023.
//

#include "../Headers/List.h"

List::List(int x, int y, int width, int height, bool visible, std::string name) :
    Component(x, y, width, height, visible, name){}

std::string List::getInfo() {
    std::string str = "List have next params: ";
    std::string outstr = str +
                         "\n1)Name: " + name +
                         "\n2)Pos_X: " + std::to_string(x) +
                         "\n3)Pos_Y: " + std::to_string(y) +
                         "\n4)Width: " + std::to_string(width) +
                         "\n5)Height: " + std::to_string(height) +
                         "\n6)Visible: " + std::to_string(visible)+
                         "\n6)Count elems: " + std::to_string(count);
    return outstr;
}

std::string List::getInfo(int n) {
    std::string tab(n, '\t');
    std::string str = "List have next params: ";
    std::string outstr = tab + str + tab +
                         "\n" + tab + "1)Name: " + name +
                         "\n" + tab + "2)Pos_X: " + std::to_string(x) +
                         "\n" + tab + "3)Pos_Y: " + std::to_string(y) +
                         "\n" + tab + "4)Width: " + std::to_string(width) +
                         "\n" + tab + "5)Height: " + std::to_string(height) +
                         "\n" + tab + "6)Visible: " + std::to_string(visible) +
                         "\n" + tab + "6)Count of elements: " + std::to_string(count);
    return outstr;
}

void List::setNewXY(int newX, int newY) {
    x = newX;
    y = newY;
}