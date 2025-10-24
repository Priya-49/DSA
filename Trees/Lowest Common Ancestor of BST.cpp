/*
Problem Statement:
------------------
Given a Binary Search Tree (BST) and two nodes p and q, find their **Lowest Common Ancestor (LCA)**.

The Lowest Common Ancestor of two nodes p and q in a BST is defined as the lowest (i.e., deepest) node
that has both p and q as descendants (a node can be a descendant of itself).

Example:
--------
Input BST:
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 2, q = 8  
Output: 6  
Explanation: The LCA of nodes 2 and 8 is 6.

p = 2, q = 4  
Output: 2  
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be an ancestor of itself.

Approach:
---------
1. Utilize the BST property:
   - All nodes in the left subtree have values smaller than the root.
   - All nodes in the right subtree have values greater than the root.
2. Start from the root and traverse:
   - If both p and q are smaller than root → move left.
   - If both p and q are greater than root → move right.
   - Otherwise, current root is the LCA (since p and q lie in different subtrees or one equals root).
3. Return the root where this condition is met.

Time Complexity:
----------------
O(h),  
where h = height of the BST.  
In a balanced BST, h = log(n), and in the worst case (skewed tree), h = n.

Space Complexity:
-----------------
O(h),  
due to recursion stack (O(log n) in balanced BST, O(n) in skewed tree).

*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        else
            return root; // Current node is the LCA
    }
};
