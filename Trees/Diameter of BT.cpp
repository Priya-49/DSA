/*
Problem Statement:
------------------
Given the 'root' of a binary tree, return the **diameter** of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in the tree.
This path may or may not pass through the root.

Example:
--------
Input:
       1
      / \
     2   3
    / \
   4   5

Output: 3

Explanation:
The longest path is [4 -> 2 -> 1 -> 3] or [5 -> 2 -> 1 -> 3], both have a length of 3 edges.

Approach:
---------
1. The idea is to compute the **height** of each node recursively.
2. For each node:
   - Compute the height of its left and right subtrees.
   - The diameter passing through that node is (left_height + right_height).
   - Update the global maximum diameter if this value is greater than the current maximum.
3. The function returns the height of the current node = 1 + max(left_height, right_height).
4. The final diameter is stored in the variable `ans`.

Time Complexity:
----------------
O(n),  
where n = number of nodes in the binary tree.  
Each node is visited exactly once.

Space Complexity:
-----------------
O(h),  
where h = height of the binary tree (recursion stack space).  
In the worst case (skewed tree), O(n).

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int ans = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        ans = max(ans, left + right); // Update diameter at each node
        return max(left, right) + 1;  // Return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};

// Example usage:
int main() {
    // Constructing the tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
