/*
Problem Statement:
------------------
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. 
You may return the answer in any order.

Example:
--------
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Explanation:
1 occurs 3 times, 2 occurs 2 times → top 2 are [1,2].

------------------------------------------------------------

Approach:
---------
1. Use a hashmap (unordered_map) to count frequencies of each number.
2. Use a min-heap (priority_queue with smallest frequency at top) to keep track of top k elements:
   - Push (frequency, element) into the heap.
   - If heap size exceeds k, pop the smallest.
3. After processing all elements, extract the elements from the heap.

------------------------------------------------------------

Time Complexity:
----------------
O(N log K)  
- Counting frequencies: O(N)  
- Pushing into heap: O(N log K)  

Space Complexity:
-----------------
O(N + K)  
- Hashmap stores frequencies of N elements, heap stores at most K elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;

        // Step 1: Count frequency
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        // Step 2: Min-heap to keep top k frequent
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        for (auto i : m) {
            minh.push({i.second, i.first});
            if ((int)minh.size() > k) minh.pop();
        }

        // Step 3: Extract results
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            v[i] = minh.top().second;
            minh.pop();
        }
        return v;
    }
};
