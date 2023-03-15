//
// Created by volch on 15.03.2023.
//

#ifndef TASK2_6_LIST_H
#define TASK2_6_LIST_H


#include "Component.h"

class List : public Component {
protected:
    int count;
public:
    List(int x, int y, int width, int height, bool visible, std::string name);
    int getCount() const { return count; }
    virtual std::string getInfo() override final;
    virtual std::string getInfo(int n) override final;

    virtual void setNewXY(int newX, int newY) override final;
};


#endif //TASK2_6_LIST_H
