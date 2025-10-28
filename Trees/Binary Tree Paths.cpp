/*
💡 Problem Statement:
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example:
Input:
    1
   / \
  2   3
   \
    5
Output: ["1->2->5","1->3"]
Explanation:
There are two paths: 1->2->5 and 1->3.

Approach:
1. Start from the root node and recursively explore all paths.
2. For each node, append its value to the current path string.
3. When a leaf node is reached (no children), add the constructed path to the result list.
4. Backtrack to explore other paths.

Time Complexity: O(N)
- Each node is visited once.

Space Complexity: O(H)
- Where H is the height of the tree (due to recursion stack).
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to build paths recursively
    void btPath(TreeNode* root, string path, vector<string>& ans) {
        // Base case: if leaf node, add complete path
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Recursive traversal for left and right subtrees
        if (root->left)
            btPath(root->left, path + "->" + to_string(root->left->val), ans);
        if (root->right)
            btPath(root->right, path + "->" + to_string(root->right->val), ans);
    }

    // Main function
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        string path = to_string(root->val);
        btPath(root, path, ans);
        return ans;
    }
};
