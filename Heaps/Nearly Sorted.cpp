/*
Problem Statement:
------------------
Given an array of size N, where each element is at most K positions away 
from its target position in the sorted order. The task is to sort the array efficiently.

Example:
--------
Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]

Explanation:
Every element is at most 3 positions away from its sorted position.

------------------------------------------------------------

Approach:
---------
1. Use a **min-heap (priority queue)** to maintain the current smallest elements.
2. Traverse through the array:
   - Push elements into the heap.
   - If heap size exceeds k, pop the smallest and place it in the array.
3. After traversal, empty the heap by popping all remaining elements back into the array.

This works because in a k-sorted array, the smallest element within any 
window of size (k+1) must be among those elements.

------------------------------------------------------------

Time Complexity:
----------------
O(N log K)  
- Each insertion/deletion in heap takes O(log K), done N times.

Space Complexity:
-----------------
O(K)  
- Heap stores at most K+1 elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int n = a.size(), j = 0;

        for (int i = 0; i < n; i++) {
            minh.push(a[i]);
            if ((int)minh.size() > k) {
                a[j++] = minh.top();
                minh.pop();
            }
        }
        while (!minh.empty()) {
            a[j++] = minh.top();
            minh.pop();
        }
    }
};
