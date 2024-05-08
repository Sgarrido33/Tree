#ifndef BST_BST_H
#define BST_BST_H

#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <string>

template<typename T>
class BST {
private:
    struct Node {
        T data;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(T _data) : data(_data) {};
    };

    Node *root;

public:
    BST(): root(nullptr){};

    Node* getRoot() const {
        return root;
    }

    void insert(T _data){
        insert(root, _data);
    }

    void insert(Node *&current, T _data) {
        if (!current)
            current = new Node(_data);
        else if (_data < current->data)
            insert(current->left, _data);
        else if (_data > current->data)
            insert(current->right, _data);
    }

    T findMin(Node* node){
        if(!node)
            return NULL;
        if(!node->left)
            return node->data;

        return findMin(node->left);
    }

    void erase(T item){
        erase(root, item);
    }

    void erase(Node*& current, T item){
        if(!current)
            return;

        if(item < current->data)
            erase(current->left, item);
        else if(item > current->data)
            erase(current->right, item);
        else if(current->left && current->right){
            T min = findMin(current->right);
            current->data = min;
            erase(current->right, min);
        }
        else{
            Node* temp = current;
            if(current->left)
                current = current->left;
            else
                current = current->right;
            delete temp;
        }
    }

    bool search(T item){
        return search(root, item);
    }

    bool search(Node* current, T item){
        if(!current)
            return false;
        else if(item < current->data)
            return search(current->left, item);
        else if(item > current->data)
            return search(current->right, item);
        else
            return true;
    }


    void pre_order(Node* current){
        if(current){
            cout << current->data << " ";
            pre_order(current->left);
            pre_order(current->right);
        }
    }

    void in_order(Node* current){
        if(current){
            in_order(current->left);
            cout << current->data << " ";
            in_order(current->right);
        }
    }

    void post_order(Node* current){
        if(current){
            post_order(current->left);
            post_order(current->right);
            cout << current->data << " ";
        }
    }

    void breadth_first_search(){
        Queue<Node*> q;
        q.enqueue(root);
        while(!q.isEmpty()){
            Node* temp = q.getFront();
            q.dequeue();
            cout << temp->data << " ";
            if(temp->left)
                q.enqueue(temp->left);
            if(temp->right)
                q.enqueue(temp->right);
        }
    }
    void depth_first_search(){
        Stack<Node*> s;
        Node* temp = root;

        while(temp || !s.empty()){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    void printBFS(){
        cout << "BFS: ";
        breadth_first_search();
    }

    void printDFS(){
        cout << "DFS: ";
        depth_first_search();
    }

};





#endif //BST_BST_H
