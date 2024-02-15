#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, vector<int>& nums) {
    if (!root) return;
    inorderTraversal(root->left, nums);
    nums.push_back(root->val);
    inorderTraversal(root->right, nums);
}

void heapify(TreeNode* root, vector<int>& nums, int& index) {
    if (!root) return;
    root->val = nums[index++];
    heapify(root->left, nums, index);
    heapify(root->right, nums, index);
}

void convertBSTtoHeap(TreeNode* root) {
    vector<int> nums;
    inorderTraversal(root, nums);
    int index = 0;
    heapify(root, nums, index);
}

void levelOrderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Before conversion: ";
    levelOrderTraversal(root);

    convertBSTtoHeap(root);

    cout << "\nAfter conversion: ";
    levelOrderTraversal(root);

    return 0;
}
