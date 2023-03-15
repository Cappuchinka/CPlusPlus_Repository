//
// Created by volch on 14.03.2023.
//

#ifndef TASK2_6_COMPONENT_H
#define TASK2_6_COMPONENT_H


#include <string>

class Component {
protected:
    int x;
    int y;
    int width;
    int height;
    bool visible;
    std::string name;
public:
    int getX() const { return x; }
    void setX(const int x) { this->x = x;}
    int getY() const { return y; }
    void setY(const int y) { this->y = y; }
    int getWidth() const { return width; }
    void setWidth(const int width) { this->width = width; }
    int getHeight() const { return height; }
    void setHeight(const int height) { this->height = height; }
    bool isVisible() const { return visible;}
    void changeVisible() { this->visible = !this->visible; }
    std::string getName() const { return name; }
    void setName(const std::string name) { this->name = name; }

    Component(int x, int y, int width, int height, bool visible, std::string name);
    Component(bool visible, std::string name);

    virtual std::string getInfo() = 0;
    virtual std::string getInfo(int n) = 0;

    virtual void setNewXY(int newX, int newY) = 0;
};


#endif //TASK2_6_COMPONENT_H
