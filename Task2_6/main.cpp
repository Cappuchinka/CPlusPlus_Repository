#include <iostream>
#include <list>
#include <limits>
#include "Classes/Headers/Component.h"
#include "Classes/Headers/Container.h"
#include "Classes/Headers/Line.h"
#include "Classes/Headers/Panel.h"
#include "Classes/Headers/Window.h"
#include "Classes/Headers/Button.h"
#include "Classes/Headers/Label.h"
#include "Classes/Headers/List.h"

int getChoice();
void changeVisibleContainer(Container* c);
void showList(std::list<Container *> &list);
void addElement(std::list<Container *> &list);
void createElement(std::list<Container *> &list);
Component* createComponent();
Container* createContainer();
void correct(int &ans);
void changeComponent(Container* c);
void changeContainer(Container* c);
void changeElement(std::list<Container *> &list);
void changeVisibleComponent(Component* c);
void changeVisibleContainer(Container* c);

int getChoice() {
    int i;
    while (true) {
        std::cout << "\nSelect action:\n1)View\n2)Add\n3)Edit\n4)Delete\n5)Exit\n";
        std::cin >> i;
        if (std::cin.good()) {
            break;
        }
        std::cout << "Incorrect data entry!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return i;
}

void showList(std::list<Container *> &list ) {
    if (list.empty()) {
        std::cout << "List is empty!\n";
        return;
    }
    else
    {
        std::string str;
        for (Container* el : list) {
            str += "\n"+el->getInfo()+"\n";
        }
        std::cout << str;
    }
}

void addElement(std::list<Container *> &list) {
    int i;
    while (true) {
        std::cout << "Select action:\n1)Add container\n2)Add element\n3)Back\n";
        std::cin >> i;
        if (std::cin.good()) {
            break;
        }
        std::cout << "Incorrect data entry!\nTry again:  ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (i == 3)
        return;
    else
    {
        switch (i)
        {
            case 1:
                list.push_back(createContainer());
                break;
            case 2:
                createElement(list);
                break;
            default:
                break;
        }
    }
}

void createElement(std::list<Container *> &list) {
    int count = 1;
    if (!list.size()) {
        std::cout << "You don't have a container to store the element!\n";
        return;
    }
    while(true){
        std::string str;
        std::cout << "Select the number of the container to which you want to add the component\n";
        for (Container* el : list) {
            str += "\n" + std::to_string(count) + ")" + "Container: " + el->getName()+"\n";
        }
        std::cout << str;
        int i;
        correct(i);
        if (i>0 && i<=list.size())
            break;

    }
    std::list<Container *>::iterator it = list.begin();
    std::advance(it,count-1);
    Container* c = *it;
    Component* com = createComponent();
    if (com)
        c->addComponent(*com);
}

Component* createComponent() {
    int choice;
    while (true) {
        std::cout << "\nSelect type:\n1)Button\n2)Label\n3)Line\n4)List\n5)Cancel\n";
        correct(choice);
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
            break;
        else if (choice == 5)
            return nullptr;
        else
            std::cout << "\nTry again!\n";
    }
    std::string str;
    int x, y, width, height,x2,y2;
    if (choice != 3) {
        std::cout << "\nEnter a name for the component: \n";
        std::cin >> str;
        std::cout << "\nEnter the x coordinate of the component location: \n";
        correct(x);
        std::cout << "\nEnter the y coordinate of the component location: \n";
        correct(y);
        std::cout << "\nEnter the width of the component: \n";
        correct(width);
        std::cout << "\nEnter the height of the component: \n";
        correct(height);
        if (choice == 1)
            return new Button(x, y, width, height, true, str);
        else if (choice == 2)
            return new Label(x, y, width, height, true, str);
        else if (choice == 3)
            return new List(x, y, width, height, true, str);
    }
    else if (choice == 3) {
        std::cout << "\nEnter name for component: \n";
        std::cin >> str;
        std::cout << "\nEnter the x1 coordinate of the component location: \n";
        correct(x);
        std::cout << "\nEnter the y1 coordinate of the component location: \n";
        correct(y);
        std::cout << "\nEnter the x2 coordinate of the component location: \n";
        correct(x2);
        std::cout << "\nEnter the y2 coordinate of the component location: \n";
        correct(y2);
        return new Line(x, y, x2, y2, true, str);
    }
    return nullptr;
}

Container* createContainer() {
    int choice;
    while (true) {
        std::cout << "\nSelect type:\n1)Panel\n2)Window\n";
        correct(choice);
        if (choice == 1 || choice == 2)
            break;
        else
            std::cout << "\nTry again!\n";
    }
    std::string str;
    int x, y, width, height;
    std::cout << "\nEnter a name for the container: \n";
    std::cin >> str;
    std::cout << "\nEnter the x coordinate of the container location: \n";
    correct(x);
    std::cout << "\nEnter the y coordinate of the container location: \n";
    correct(y);
    std::cout << "\nEnter the width of the component: \n";
    correct(width);
    std::cout << "\nEnter the height of the component: \n";
    correct(height);
    if (choice == 1)
        return new Panel(x, y, width, height, str);
    else if (choice == 2)
        return new Window(x, y, width, height, str);
    return nullptr;

}

void correct(int &ans) {
    while (true) {
        std::cin >> ans;
        if (std::cin.good()) {
            break;
        }
        std::cout << "Incorrect data entry!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void deleteElement(std::list<Container *> &list) {
    std::cout << "Not implemented yet.";
    return;
}

void changeElement(std::list<Container *> &list) {
    if (list.empty()) {
        std::cout << "Don't have elements!\n";
        return;
    }
    else
    {
        int i= 1;
        std::string str = "\nSelect the container whose visibility (position) you want to change, or change the visibility (position) its members\n";
        for (Container* el : list)
            str += std::to_string(i) +")Container " + el->getName() + "\n";
        int choice;
        while (true) {
            std::cout << str;
            correct(choice);
            if (choice > 0 && choice <= list.size())
                break;
            else
                std::cout << "\nTry again!\n";
        }
        std::list<Container *>::iterator it = list.begin();
        std::advance(it, choice-1);
        Container* c = *it;

        while (true) {
            std::cout << "\nSelect action:\n1)Change the visibility (position) of the container \n2)Viewing its components\n";
            correct(choice);
            if (choice == 1 || choice == 2)
                break;
            else
                std::cout << "\nTry again!\n";
        }

        if (choice == 1)
            changeContainer(c);
        else if (choice == 2)
            changeComponent(c);
    }
}

void changeVisibleContainer(Container* c ) {
    c->changeVisible();
    std::cout << "\nVisible is changed.\n";
}

void changeVisibleComponent(Component* c) {
    c->changeVisible();
    std::cout << "\nVisible is changed.\n";
}

void changeComponent(Container* c) {
    std::list<Component *> list = c->getList();
    int i = 1;
    std::string str = "\nSelect the container component whose visibility you want to change, or change the position\n";
    for (Component* el : list)
        str += std::to_string(i) + ")Component " + el->getName() + "\n";
    int choice;
    while (true) {
        std::cout << str;
        correct(choice);
        if (choice > 0 && choice <= list.size())
            break;
        else
            std::cout << "\nTry again!\n";
    }
    std::list<Component *>::iterator it = list.begin();
    std::advance(it, choice - 1);
    Component* er = *it;
    while (true) {
        std::cout << "\nSelect action:\n1)Change visible\n2)Change position\n";
        correct(choice);
        if (choice == 1 || choice == 2)
            break;
        else
            std::cout << "\nTry again!\n";
    }
    if (choice == 1)
        changeVisibleComponent(er);
    else if (choice == 2) {
        int x, y;
        std::cout << "\nEnter coordination X of Container: \n";
        correct(x);
        std::cout << "\nEnter coordination Y of Container: \n";
        correct(y);
        er->setNewXY(x, y);
        std::cout << "\nPosition is changed.\n";
    }

}

void changeContainer(Container* c) {
    int choice;
    while (true) {
        std::cout << "\nSelect action:\n1)Change visible\n2)Change position\n";
        correct(choice);
        if (choice == 1 || choice == 2)
            break;
        else
            std::cout << "\nTry again!\n";
    }
    if (choice == 1)
        changeVisibleContainer(c);
    else if (choice == 2) {
        int x, y;
        std::cout << "\nEnter coordination X of Container: \n";
        correct(x);
        std::cout << "\nEnter coordination Y of Container: \n";
        correct(y);
        c->setNewXY(x, y);
        std::cout << "\nPosition is changed.\n";
    }

}

int main()
{
    int ans = 0;
    std::list<Container *> list;
    while (ans!=5) {
        ans = getChoice();
        switch (ans)
        {
            case 1:
                showList(list);
                break;
            case 2:
                addElement(list);
                break;
            case 3:
                changeElement(list);
                break;
            case 4:
                deleteElement(list);
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}
