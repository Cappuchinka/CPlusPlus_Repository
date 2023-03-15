//
// Created by volch on 15.03.2023.
//

#ifndef TASK2_6_LABEL_H
#define TASK2_6_LABEL_H


#include "Component.h"

class Label : public Component {
public:
    Label(int x, int y, int width, int height, bool visible, std::string name);
    virtual std::string getInfo() override final;
    virtual std::string getInfo(int n) override final;

    virtual void setNewXY(int newX, int newY) override final;
};


#endif //TASK2_6_LABEL_H
