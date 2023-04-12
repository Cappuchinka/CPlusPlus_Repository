#include <iostream>
#include "simpleQueue.h"

int main() {
    std::cout << "\n================================================================================\n" << std::endl;

    simpleQueue::MySimpleQueue<int> qInt{};

    qInt.printQueue("int");
    std::cout << "Queue size: " << qInt.size() << std::endl;
    std::cout << std::endl;

    qInt.push(1);
    qInt.printQueue("int");
    std::cout << std::endl;
    qInt.push(2);
    qInt.printQueue("int");
    std::cout << std::endl;
    qInt.push(3);
    qInt.printQueue("int");
    std::cout << std::endl;
    qInt.push(4);
    qInt.printQueue("int");
    std::cout << std::endl;
    qInt.push(5);
    qInt.printQueue("int");
    std::cout << std::endl;

    std::cout << "Queue size after push: " << qInt.size() << std::endl;
    qInt.printQueue("int");

    std::cout << "\nHead of Queue: " << qInt.first() << std::endl;
    std::cout << "Tail of Queue: " << qInt.back() << std::endl;

    std::cout << "\nRemove head: " << qInt.pop() << "; New head: " << qInt.first() << std::endl;

    std::cout << "\nQueue size after pop: " << qInt.size() << std::endl;
    qInt.printQueue("int");

    std::cout << "\n================================================================================\n" << std::endl;

    simpleQueue::MySimpleQueue<std::string> qStr{};

    qStr.printQueue("string");
    std::cout << "Queue size: " << qStr.size() << std::endl;

    qStr.push(std::string{"Coffee"});
    qStr.printQueue("string");
    std::cout << std::endl;
    qStr.push(std::string{"Beer"});
    qStr.printQueue("string");
    std::cout << std::endl;
    qStr.push(std::string{"Wine"});
    qStr.printQueue("string");
    std::cout << std::endl;
    qStr.push(std::string{"Baikal"});
    qStr.printQueue("string");
    std::cout << std::endl;
    qStr.push(std::string{"Gin"});
    qStr.printQueue("string");
    std::cout << std::endl;
    qStr.push(std::string{"Whiskey"});
    qStr.printQueue("string");
    std::cout << std::endl;


    std::cout << "Queue size after push: " << qStr.size() << std::endl;
    qStr.printQueue("string");

    std::cout << "\nHead of Queue: " << qStr.first() << std::endl;
    std::cout << "Tail of Queue: " << qStr.back() << std::endl;

    std::cout << "\nRemove head: " << qStr.pop() << "; New head: " << qStr.first() << std::endl;

    std::cout << "\nQueue size after pop: " << qStr.size() << std::endl;
    qStr.printQueue("string");

    std::cout << "\n================================================================================\n" << std::endl;

    return 0;
}
