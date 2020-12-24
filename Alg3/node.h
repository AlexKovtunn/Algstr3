
#pragma once
class Node {
public:
    Node* left, * right;
    int inf;

    Node() {
        inf = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(const int& node_inf, Node* node_left, Node* node_right) {
        inf = node_inf;
        left = node_left;
        right = node_right;
    }
};