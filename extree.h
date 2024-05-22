class Solution {
public:
    int count; 
    int result; 

    void inorder(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left, k); 

        count++;do
        if (count == k) {
            result = node->val; 
            return;
        }

        inorder(node->right, k); 
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0; 
        inorder(root, k);
        return result; 
    }
};
