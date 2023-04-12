//
// Created by volch on 09.04.2023.
//

#ifndef TASK3_6_SIMPLEQUEUE_H
#define TASK3_6_SIMPLEQUEUE_H

#include <iostream>

namespace simpleQueue
{
    // Класс элемента очереди
    template<typename T>
    class QueueItem {
    public:
        QueueItem():value(T()), next(nullptr) {}
        QueueItem(T value):value(value), next(nullptr) {}

        T& getValue();

        void setValue(const T& value);

        QueueItem<T> *getNext();
        void setNext(QueueItem<T>* next);

    private:
        T value;
        QueueItem<T> *next;
    };

    template<typename T>
    T& QueueItem<T>::getValue() {
        return value;
    }

    template<typename T>
    void QueueItem<T>::setValue(const T& value) {
        this->value = value;
    }

    template<typename T>
    QueueItem<T> *QueueItem<T>::getNext() {
        return next;
    }

    template<typename T>
    void QueueItem<T>::setNext(QueueItem<T>* next) {
        this->next = next;
    }

//// =========================================================================================

    // Класс реализации очереди
    template<typename T>
    class MySimpleQueue {
    public:
        using node = QueueItem<T>*;

        MySimpleQueue() : queueSize(0) {
            head = tail = nullptr;
        }

        ~MySimpleQueue();

        std::size_t size(); // получить количество элементов в очереди

        bool isEmpty(); // проверка очереди на пустоту

        void push(const T& elem); // положить голову

        T pop(); // удалить голову

        T &first(); // будет первым удалён из очереди
        T &back(); // получить хвост (хвост в очереди, а не хвост по дисциплине)

        void printQueue(std::string type);

    private:
        QueueItem<T>* head;
        QueueItem<T>* tail;
        std::size_t queueSize;
    };

    template<typename T>
    MySimpleQueue<T>::~MySimpleQueue() {
        if (tail != nullptr) {
            while (tail != head) {
                node temp = tail;
                tail = tail->getNext();
                delete temp;
            }
            delete tail;
        }
    }

    template<typename T>
    std::size_t MySimpleQueue<T>::size() {
        return queueSize;
    }

    template<typename T>
    bool MySimpleQueue<T>::isEmpty() {
        return queueSize == 0;
    }

    template<typename T>
    void MySimpleQueue<T>::push(const T& elem) {
        if (queueSize == 0) {
            tail = new QueueItem<T>(elem);
            head = tail;
        } else {
            node temp = new QueueItem<T>(elem);
            temp->setNext(tail);
            tail = temp;
        }
        queueSize++;
    }

    template<typename T>
    T &MySimpleQueue<T>::first() {
        if (isEmpty()) {
            throw "Queue is empty.";
        }
        return head->getValue();
    }

    template<typename T>
    T &MySimpleQueue<T>::back() {
        if (isEmpty()) {
            throw "Queue is empty.";
        }
        return tail->getValue();
    }

    template<typename T>
    T MySimpleQueue<T>::pop() {
        if (isEmpty()) {
            throw "Queue is empty.";
        }
        node temp = tail;
        T headValue;
        while(temp->getNext() != head) {
            temp = temp->getNext();
        }
        if (temp->getNext() == head) {
            headValue = head->getValue();
            temp->setNext(nullptr);
            delete head;
            head = temp;
        }
        queueSize--;
        return headValue;
    }

    template<typename T>
    void MySimpleQueue<T>::printQueue(std::string type) {
        std::cout << "Queue " << type << ": ";
        if (isEmpty())
        {
            std::cout << "empty." << std::endl;
            return;
        }
        node cursor = tail;
        while (cursor->getNext() != nullptr) {
            std::cout << cursor->getValue() << " --> ";
            cursor = cursor->getNext();
        }
        std::cout << cursor->getValue() << std::endl;
    }

}

#endif //TASK3_6_SIMPLEQUEUE_H
