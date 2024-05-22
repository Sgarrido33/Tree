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






class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        inorderTraversal(root, prev, minDiff);
        return minDiff;
    }

private:
    void inorderTraversal(TreeNode* node, TreeNode*& prev, int& minDiff) {
        if (node == nullptr) {
            return;
        }


        inorderTraversal(node->left, prev, minDiff);

  
        if (prev != nullptr) {
            minDiff = min(minDiff, node->val - prev->val);
        }
        prev = node;


        inorderTraversal(node->right, prev, minDiff);
    }
};
