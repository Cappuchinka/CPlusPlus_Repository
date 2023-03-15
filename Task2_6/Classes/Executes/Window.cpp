//
// Created by volch on 15.03.2023.
//

#include "../Headers/Window.h"
Window::Window(int x, int y, int width, int height, std::string name, bool visible) :
        Container(x, y, width, height, visible, name) {}

std::string Window::getInfo() {
    std::string str = "Window " + name + " have next params: ";
    std::string strlist;
    if (listOfComponents.size() > 0) {
        for (Component* el : listOfComponents)
            strlist += "\n\t"+el->getInfo(3);
    }

    std::string outstr = str +
                         "\n1)Pos_X: " + std::to_string(x) +
                         "\n2)Pos_Y: " + std::to_string(y) +
                         "\n3)Width: " + std::to_string(width) +
                         "\n4)Height: " + std::to_string(height) +
                         "\n5)Visible: " + std::to_string(visible) +
                         "\n6)Count elems in Container: " + std::to_string(listOfComponents.size()) + strlist;
    return outstr;
}

std::string Window::getInfo(int n) {}

void Window::setNewXY(int newX, int newY) {
    x = newX;
    y = newY;
}
