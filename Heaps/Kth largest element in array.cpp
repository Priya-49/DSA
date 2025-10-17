/*
Problem Statement:
------------------
Given an integer array 'nums' and an integer 'k', return the k-th largest element in the array.
Note that it is the k-th largest element in sorted order, not the k-th distinct element.

Example:
--------
Input: nums = [3,2,1,5,6,4], k = 2  
Output: 5

Explanation:  
If we sort the array in descending order → [6,5,4,3,2,1].  
The 2nd largest element is 5.

Approach:
---------
1. Use a Min-Heap (priority_queue with 'greater<int>') of size 'k'.
2. Traverse each element in 'nums':
   - Push the element into the heap.
   - If the heap size exceeds 'k', remove the smallest element (min-heap property).
3. After processing all elements, the top of the heap will be the k-th largest element.

Time Complexity:
----------------
O(n * log k),  
where n = size of 'nums'.  
(Each push/pop operation in a heap of size 'k' takes O(log k)).

Space Complexity:
-----------------
O(k),  
for storing the heap elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh; // Min-Heap

        for(int i = 0; i < nums.size(); i++) {
            minh.push(nums[i]);
            if(minh.size() > k)
                minh.pop(); // Maintain heap size = k
        }

        return minh.top(); // Root of heap = k-th largest
    }
};
