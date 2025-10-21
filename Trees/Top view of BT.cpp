/*
Problem Statement:
------------------
Given a binary tree, print the **top view** of the binary tree.

The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
In other words, for each horizontal distance from the root, the first node encountered during level order traversal is part of the top view.

Example:
--------
Input Tree:
       1
     /   \
    2     3
     \   / \
      4 5   6

Output:
2 1 3 6

Explanation:
From the top, the nodes visible are [2, 1, 3, 6].

Approach:
---------
1. Use **Level Order Traversal (BFS)** to ensure that the topmost node at each horizontal distance (HD) is encountered first.
2. Maintain:
   - A **map<int, Node*>** to store the first node encountered for each horizontal distance (HD).
   - A **queue<pair<Node*, int>>** to store nodes along with their HD values.
3. Start from the root with HD = 0.
   - For every node:
     - If the current HD is not present in the map, insert the node.
     - Move left child with HD - 1, right child with HD + 1.
4. Finally, iterate over the map (which is sorted by HD) and extract node values for the top view.

Time Complexity:
----------------
O(n * log n),  
where n = number of nodes in the tree.  
(Map insertion and traversal take O(log n) each time.)

Space Complexity:
-----------------
O(n),  
for the queue and map used during traversal.

*/


// Definition for a binary tree node.
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
    vector<int> topView(Node *root) {
        if (!root) return {};

        map<int, Node*> m; // Maps horizontal distance -> node
        queue<pair<Node*, int>> q; // Queue for BFS (node, horizontal distance)

        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int currHD = q.front().second;
            q.pop();

            // Store only the first node encountered for each HD
            if (m.find(currHD) == m.end())
                m[currHD] = curr;

            if (curr->left)
                q.push({curr->left, currHD - 1});
            if (curr->right)
                q.push({curr->right, currHD + 1});
        }

        vector<int> result;
        for (auto i : m)
            result.push_back(i.second->data);

        return result;
    }
};
