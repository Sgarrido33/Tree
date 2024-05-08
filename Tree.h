#ifndef BST_TREE_H
#define BST_TREE_H

#include "Queue.h"
#include "Stack.h"

#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    void preOrderTraversal(TreeNode* root) {
        if (root) {
            cout << root->val << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void inOrderTraversal(TreeNode* root) {
        if (root) {
            inOrderTraversal(root->left);
            cout << root->val << " ";
            inOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(TreeNode* root) {
        if (root) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->val << " ";
        }
    }

    // Works on BST
    TreeNode* successor(TreeNode* root, int target) {
        TreeNode* succ = nullptr;
        while (root) {
            if (root->val > target) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }

    // Works on BST
    TreeNode* predecessor(TreeNode* root, int target) {
        TreeNode* pred = nullptr;
        while (root) {
            if (root->val < target) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
    }

    void BFS(TreeNode* root) {
        if (!root) return;

        Queue<TreeNode*> q;
        q.enqueue(root);

        while (!q.isEmpty()) {
            TreeNode* current = q.getFront();
            q.dequeue();
            cout << current->val << " ";

            if (current->left) q.enqueue(current->left);
            if (current->right) q.enqueue(current->right);
        }
    }

    void DFS(TreeNode* root) {
        if (!root) return;

        Stack<TreeNode*> s;
        s.push(root);

        while (!s.isEmpty()) {
            TreeNode* current = s.Top();
            s.pop();
            cout << current->val << " ";

            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    void mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return;

        if (root2->val < root1->val) {
            root1->left = root2;
        } else {
            root1->right = root2;
        }
    }

    TreeNode* findLeaf(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) return root;
        TreeNode* left = findLeaf(root->left);
        TreeNode* right = findLeaf(root->right);
        return left ? left : right;
    }

    // s = main tree
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false; // If root is null, can't be a subtree
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true; // Both nodes are null, Are equal
        if (!s || !t) return false; // One node is null, Not equal
        return (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

};


#endif //BST_TREE_H
