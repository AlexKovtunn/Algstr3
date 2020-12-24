#pragma once
#include "elem.h"
class queue {
private:
    size_t size;
    Elem* begin, * end;
public:
    queue() {
        size = 0;
        begin = nullptr;
        end = nullptr;
    }

    Node* front() {
        return begin->value;
    }

    Node* back() {
        return end->value;
    }

    bool isEmpty() {
        if (size == 0) return true;
        else return false;
    }

    size_t getSize() {
        return size;
    }

    void push(Node* value) {
        Elem* temp = new Elem(value, nullptr);
        if (isEmpty()) begin = temp;
        else end->next = temp;
        end = temp;
        size++;
    }

    void pop() {
        Elem* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};