#pragma once
#include "node.h"
class Elem {
public:
    Elem* next;
    Node* value;
    Elem(Node* elem_value, Elem* elem_next) {
        value = elem_value;
        next = elem_next;
    }
};