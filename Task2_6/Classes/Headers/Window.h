//
// Created by volch on 15.03.2023.
//

#ifndef TASK2_6_WINDOW_H
#define TASK2_6_WINDOW_H


#include "Container.h"

class Window : public Container {
public:
    Window(int x, int y, int width, int height, std::string name, bool visible = true);
    virtual std::string getInfo() override final;
    virtual std::string getInfo(int n) override final;

    virtual void setNewXY(int newX, int newY) override final;
};


#endif //TASK2_6_WINDOW_H
