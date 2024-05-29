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







class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr and t2 == nullptr) {
        return true;
    }
    if (t1 == nullptr or t2 == nullptr) {
        return false;
    }
    return (t1->val == t2->val) and isMirror(t1->left,t2->right) and isMirror(t1->right,t2->left);
}

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};




















#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void maxHeapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // Inicializamos el más grande como raíz
    int left = 2 * i + 1; // hijo izquierdo
    int right = 2 * i + 2; // hijo derecho

    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si el hijo derecho es más grande que el más grande hasta ahora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si el más grande no es la raíz
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Heapify el subárbol afectado
        maxHeapify(arr, n, largest);
    }
}

TreeNode* buildMaxHeapTree(std::vector<int>& arr) {
    int n = arr.size();

    // Construir el heap (reorganizar el array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Crear la raíz del árbol
    TreeNode* root = new TreeNode(arr[0]);

    // Utilizamos una cola para gestionar los nodos y construir el árbol
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (i < n) {
            current->left = new TreeNode(arr[i++]);
            q.push(current->left);
        }

        if (i < n) {
            current->right = new TreeNode(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    std::vector<int> arr = {3, 9, 2, 1, 4, 5};

    TreeNode* maxHeapRoot = buildMaxHeapTree(arr);
    std::cout << "Max Heap Tree: ";
    printTree(maxHeapRoot);
    std::cout << std::endl;

    return 0;
}






void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i; // Inicializamos el más pequeño como raíz
    int left = 2 * i + 1; // hijo izquierdo
    int right = 2 * i + 2; // hijo derecho

    // Si el hijo izquierdo es más pequeño que la raíz
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Si el hijo derecho es más pequeño que el más pequeño hasta ahora
    if (right < n && arr[right] < arr[smallest])
        smallest = right
    // Si el más pequeño no es la raíz
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);

        // Heapify el subárbol afectado
        minHeapify(arr, n, smallest);
    }
}

TreeNode* buildMinHeapTree(std::vector<int>& arr) {
    int n = arr.size();

    // Construir el heap (reorganizar el array)
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Crear la raíz del árbol
    TreeNode* root = new TreeNode(arr[0]);

    // Utilizamos una cola para gestionar los nodos y construir el árbol
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (i < n) {
            current->left = new TreeNode(arr[i++]);
            q.push(current->left);
        }

        if (i < n) {
            current->right = new TreeNode(arr[i++]);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    std::vector<int> arr = {3, 9, 2, 1, 4, 5};

    TreeNode* minHeapRoot = buildMinHeapTree(arr);
    std::cout << "Min Heap Tree: ";
    printTree(minHeapRoot);
    std::cout << std::endl;

    return 0;
}






























void insertMaxHeap(std::vector<int>& arr, int val) {
    arr.push_back(val);
    int i = arr.size() - 1;
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        std::swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int deleteMaxHeap(std::vector<int>& arr) {
    if (arr.size() == 0)
        return -1;

    int root = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    maxHeapify(arr, arr.size(), 0);

    return root;
}


void convertToMinHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}
