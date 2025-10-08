/*
Problem Statement:(Leetcode 572)
------------------
Given two binary trees 'root' and 'subRoot', determine if 'subRoot' is a subtree of 'root'.
A subtree of a binary tree 'root' is a tree consisting of a node in 'root' and all of its descendants.
The tree 'root' could also be considered as a subtree of itself.

Approach:
---------
1. Write a helper function `isIdentical` to check if two trees are identical.
   - Two trees are identical if the root values are equal and their left and right subtrees are identical.
2. In the `isSubtree` function:
   - If the current node's value equals the root of subRoot, check if the trees are identical using `isIdentical`.
   - Otherwise, recursively check for subtree in the left and right children of the current node.

Time Complexity:
----------------
- Worst-case: O(m * n), where m = number of nodes in 'root' and n = number of nodes in 'subRoot'.
  (Each node in 'root' may trigger a full comparison with 'subRoot'.)

Space Complexity:
-----------------
- O(h) recursion stack space, where h is the height of 'root'.
*/


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
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) 
            return root == subRoot;  // Both should be NULL to be identical
        return root->val == subRoot->val 
               && isIdentical(root->left, subRoot->left) 
               && isIdentical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) 
            return root == subRoot;
        
        if(root->val == subRoot->val && isIdentical(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
