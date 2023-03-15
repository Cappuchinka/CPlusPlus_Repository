//
// Created by volch on 14.03.2023.
//

#ifndef TASK2_6_CONTAINER_H
#define TASK2_6_CONTAINER_H


#include <list>
#include "Component.h"

class Container : public Component {
protected:
    std::list<Component*> listOfComponents;
public:
    std::list<Component*> getList() { return listOfComponents; }
    void addComponent(Component &c) { listOfComponents.push_back(&c); }
    Container(int x, int y, int width, int height, bool visible, std::string name);

    virtual std::string getInfo() = 0;

    virtual void setNewXY(int newX, int newY) = 0;
};


#endif //TASK2_6_CONTAINER_H
