/*
Problem Statement:
------------------
Given two integer arrays `preorder` and `inorder` representing the preorder and inorder traversal 
of a binary tree, construct and return the binary tree.

Example:
--------
Input:
preorder = [3,9,20,15,7]
inorder  = [9,3,15,20,7]

Output:
        3
       / \
      9  20
         / \
        15  7

Explanation:
- Preorder traversal visits nodes in the order: Root → Left → Right
- Inorder traversal visits nodes in the order: Left → Root → Right
Using these two traversals, we can reconstruct the tree uniquely.

Approach:
---------
1. In preorder, the first element is always the root of the tree.
2. In inorder, elements to the left of the root belong to the left subtree,
   and elements to the right belong to the right subtree.
3. Use recursion to:
   - Pick the current root from preorder using an index `preIdx`.
   - Find the index of that root in the inorder array using a hash map (for O(1) lookup).
   - Recursively build the left and right subtrees.
4. Continue until the left index > right index (base condition).

Time Complexity:
----------------
O(n),  
where n = number of nodes.
Each node is processed once, and lookup in the hash map is O(1).

Space Complexity:
-----------------
O(n),  
for the recursion stack and hash map storing inorder indices.

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right, unordered_map<int,int>& inmap) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = inmap[preorder[preIdx]];
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1, inmap);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for (int i = 0; i < inorder.size(); i++)
            inmap[inorder[i]] = i;

        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1, inmap);
    }
};

// Example usage:
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
