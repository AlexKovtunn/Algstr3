#pragma once
#include "queue.h"
#include "stack.h"
#include "iterator.h"
#include "node.h"
//breadth-first traverse
class bft_iterator : public Iterator {
private:
    Node* cur;
    queue nodesQueue;
public:
    bft_iterator(Node* root) {
        cur = root;
        if (cur != nullptr) {
            nodesQueue.push(cur);
        }
        else {
            throw "This tree is empty";
        }
    }
    //moving to the next element
    int next() override {
        if (nodesQueue.getSize() > 0) {
            cur = nodesQueue.front();
            nodesQueue.pop();
            if (cur->left != nullptr) {
                nodesQueue.push(cur->left);
            }
            if (cur->right != nullptr) {
                nodesQueue.push(cur->right);
            }
            return cur->inf;
        }
        else cur = nullptr;
    }
     //checking for the presence of the following element
    bool has_next() override {
        if (cur->left == nullptr && cur->right == nullptr) return false;
        else return true;
    }
};
//depth-first traverse
class dft_iterator : public Iterator {
private:
    Node* cur;
    stack nodesStack;
    bool flag = true;
public:
    dft_iterator(Node* root) {
        cur = root;
        if (cur != nullptr) {
            nodesStack.push(cur);
        }
        else {
            throw "This tree is empty";
        }
    }

    int next() override {
        if (flag) {
            flag = false;
            Node* temp = nodesStack.getTop();
            nodesStack.pop();
            return temp->inf;
        }
        if (cur->right != nullptr) nodesStack.push(cur->right);
        if (cur->left != nullptr) cur = cur->left;
        else
            if (!nodesStack.isEmpty()) {
                cur = nodesStack.getTop();
                nodesStack.pop();
            }
            else cur = nullptr;
        return cur->inf;
    }

    bool has_next() override {
        if (cur->left == nullptr && cur->right == nullptr) return false;
        else return true;
    }

};
// Binary search tree
class BST {
private:
    Node* root;
public:
    BST() {
        root = nullptr;
    }

    bool contains(const int& value) { // search for an element in the tree by key
        if (root == nullptr) {
            throw "This tree is empty";
            return false;
        }
        Node* temp = root;
        while (value != temp->inf) {
            if (value > temp->inf)
                if (temp->right != nullptr) temp = temp->right;
                else return false;
            else
                if (temp->left != nullptr) temp = temp->left;
                else return false;

        }
        return true;
    }
    void insert(const int& value) { //adding an element to the tree by key
        if (root == nullptr) root = new Node(value, nullptr, nullptr);
        else {
            Node* temp = root;
            while (true) {
                if (value > temp->inf)
                    if (temp->right != nullptr) temp = temp->right;
                    else {
                        temp->right = new Node(value, nullptr, nullptr);
                        break;
                    }
                else
                    if (temp->left != nullptr) temp = temp->left;
                    else {
                        temp->left = new Node(value, nullptr, nullptr);
                        break;
                    }
            }
        }
    }
    void remove(const int& value) { //the removal of the tree element by key
        if (root == nullptr) throw "This tree is empty";
        if (!contains(value)) throw "This element isn`t in tree";
        else {
            Node* cur = root, * prev = nullptr;
            while (value != cur->inf) {
                prev = cur;
                if (value < cur->inf) cur = cur->left;
                else cur = cur->right;
            }
            if (cur->left == nullptr && cur->right == nullptr) {
                if (prev->left->inf = cur->inf) prev->left = nullptr;
                else  prev->right = nullptr;
                delete cur;
            }
            else
                if (cur->left != nullptr && cur->right != nullptr) {
                    Node* temp;
                    if (cur->right->left != nullptr) {
                        temp = cur->right->left;
                        cur->inf = temp->inf;
                        cur->right->left = nullptr;
                    }
                    else {
                        temp = cur->right;
                        cur->inf = temp->inf;
                        Node* new_Node = new Node(temp->right->inf, temp->right->left, temp->right->right);
                        cur->right = new_Node;
                    }
                    delete temp;
                }
                else {
                    if (cur->left != nullptr) {
                        cur->inf = cur->left->inf;
                        delete cur->left;
                        cur->left = nullptr;
                    }
                    else {
                        cur->inf = cur->right->inf;
                        delete cur->right;
                        cur->right = nullptr;
                    }
                }
        }
    }

    Iterator* create_bft_iterator() {
        return new bft_iterator(root);
    }
    Iterator* create_dft_iterator() {
        return new dft_iterator(root);
    }
};