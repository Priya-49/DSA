/*
Problem Statement:
------------------
Given an array of points `p` on a 2D plane, return the `k` closest points to the origin (0,0).  
The distance between two points (x1, y1) and (x2, y2) is calculated using the Euclidean distance formula.  
You may return the answer in any order. The answer is guaranteed to be unique.

Approach:
---------
1. Use a Max-Heap (priority_queue) to keep track of the k closest points.
2. For each point in 'p':
   - Calculate its squared distance from the origin: d = x^2 + y^2
   - Push (distance, point) pair into the max-heap.
   - If heap size exceeds k, remove the point with the largest distance (max-heap property).
3. After processing all points, the heap will contain the k closest points.
4. Extract all points from the heap to return the result.

Time Complexity:
----------------
O(n * log k),  
where n = number of points.  
Each push/pop in the heap of size k takes O(log k).

Space Complexity:
-----------------
O(k),  
for storing the k closest points in the heap.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        int n = p.size();
        priority_queue<pair<int, vector<int>>> maxh; // Max-Heap
        
        for(int i = 0; i < n; i++) {
            int d = p[i][0]*p[i][0] + p[i][1]*p[i][1]; // Squared distance
            maxh.push({d, p[i]});
            if(maxh.size() > k)
                maxh.pop(); // Keep only k closest points
        }

        vector<vector<int>> result(k);
        for(int i = 0; i < k; i++) {
            result[i] = maxh.top().second;
            maxh.pop();
        }

        return result;
    }
};

