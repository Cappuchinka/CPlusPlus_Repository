//
// Created by volch on 15.03.2023.
//

#ifndef TASK2_6_PANEL_H
#define TASK2_6_PANEL_H


#include "Container.h"

class Panel : public Container {
public:
    Panel(int x, int y, int width, int height, std::string name, bool visible = true);
    virtual std::string getInfo() override final;
    virtual std::string getInfo(int n) override final;

    virtual void setNewXY(int newX, int newY) override final;
};


#endif //TASK2_6_PANEL_H
