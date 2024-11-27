// Name : Charlie Tuesares
// ID : 1123532
// Date : 11/27/2024

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree using level-order input
TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter and height of the binary tree
int diameterHelper(TreeNode* root, int& diameter) {
    if (!root) {
        return 0;
    }

    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);

    // Update the diameter
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current subtree
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of the binary tree
int calculateDiameter(TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}

// Main function
int main() {
    // Input: Level-order traversal of the binary tree
    vector<int> levelOrder = {1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7};

    TreeNode* root = buildTree(levelOrder);
    int diameter = calculateDiameter(root);

    // Output the diameter
    cout << diameter << endl;

    return 0;
}
