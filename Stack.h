#ifndef BST_STACK_H
#define BST_STACK_H

#include <iostream>
using namespace std;


// Implementation with Linked List
template <class T>
class StackNode {
public:
    T data;
    StackNode* next;

    StackNode(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(T data) {
        StackNode<T>* newNode = new StackNode<T>(data);
        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            return T();
        } else {
            StackNode<T>* temp = top;
            T poppedData = temp->data;
            top = top->next;
            delete temp;
            return poppedData;
        }
    }

    T Top() {
        if (isEmpty()) {
            return T();
        } else {
            return top->data;
        }
    }

    int size() {
        int count = 0;
        StackNode<T>* current = top;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    Stack& operator=(const Stack& other) {
        if (this == &other) {
            return *this;
        }
        clear(); // Limpiar la pila actual
        StackNode<T>* current = other.top;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
        return *this;
    }


};

#endif //BST_STACK_H
