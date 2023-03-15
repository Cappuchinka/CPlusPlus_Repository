//
// Created by volch on 15.03.2023.
//

#ifndef TASK2_6_LINE_H
#define TASK2_6_LINE_H


#include "Component.h"

class Line : public Component {
protected:
    int x1, y1, x2, y2;
public:
    Line(int x1, int y1, int x2, int y2, bool visible, std::string name);
    void newCoordinates(int newX1, int newY1, int newX2, int newY2);
    virtual std::string getInfo() override final;
    virtual std::string getInfo(int n) override final;

    virtual void setNewXY(int newX, int newY) override final;
};


#endif //TASK2_6_LINE_H
