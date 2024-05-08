#include "BST.h"
#include "Tree.h"

int main(){
    // BST
    BST<int> tree;

    tree.insert(23);
    tree.insert(38);
    tree.insert(2);
    tree.insert(14);
    tree.insert(32);
    tree.insert(90);
    tree.insert(32);

    tree.printBFS();
    cout<<" "<<endl;
    tree.erase(23);

    if(tree.search(23)){
        cout<<"23 Found"<<endl;
    }

    if(tree.search(2)){
        cout<<"2 Found"<<endl;
    }







    // Tree to do exercises

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;

    cout << "In-order traversal: ";
    solution.inOrderTraversal(root);
    cout << endl;

    //Subtree example
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->right = new TreeNode(5);
    s->left->left = new TreeNode(1);
    s->left->right = new TreeNode(2);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    Solution solution2;


    if (solution2.isSubtree(s, t))
        cout << "t is a subtree of s" << endl;
    else
        cout << "t is not a subtree of s" << endl;



}