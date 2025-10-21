/*
Problem Statement:
------------------
Given a binary tree and an integer K, print all the nodes that are at distance K from the root.

The distance between two nodes is the number of edges on the path between them.

Example:
--------
Input Tree:
        1
       / \
      2   3
     / \   \
    4   5   8
             \
              6

K = 2

Output: 4 5 8

Explanation:
Nodes at distance 2 from the root are [4, 5, 8].

Approach:
---------
1. Perform a simple recursive traversal.
2. For each node:
   - If k == 0 → it means we have reached the required distance, so print/store this node's value.
   - Otherwise, recursively call for left and right subtrees with (k - 1).
3. Stop recursion when the node is NULL or k < 0.

Time Complexity:
----------------
O(n),  
where n = number of nodes in the binary tree.  
Each node is visited once.

Space Complexity:
-----------------
O(h),  
where h = height of the tree (recursion stack space).

*/

#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> result;

    void kdist(Node* root, int k) {
        if (root == nullptr) return;

        if (k == 0) {
            result.push_back(root->data);
            return;
        }

        kdist(root->left, k - 1);
        kdist(root->right, k - 1);
    }

    vector<int> Kdistance(Node *root, int k) {
        kdist(root, k);
        return result;
    }
};
