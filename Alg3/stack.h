#pragma once
#include "elem.h"
class stack {
private:
    size_t size;
    Elem* top;
public:
    stack() {
        size = 0;
        top = nullptr;
    }

    Node* getTop() {
        return top->value;
    }

    void pop()
    {
        Elem* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void push(Node* value) {
        top = new Elem(value, top);
        size++;
    }

    size_t getSize() {
        return size;
    }
    bool isEmpty() {
        if (size == 0) return true;
        else return false;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};