/*
Problem Statement:
------------------
You are given an array `heights[]` representing the histogram’s bar height 
where the width of each bar is 1. 
Return the area of the largest rectangle in the histogram.

Example:
--------
Input: heights = [2,1,5,6,2,3]
Output: 10

Explanation:
The largest rectangle is 5x2 = 10 (bars of height 5 and 6 together).

------------------------------------------------------------

Approach:
---------
1. For each bar, we want to know:
   - The index of the **next smaller element to the right**.
   - The index of the **next smaller element to the left**.

2. With these two, we can compute the "width" of the rectangle 
   where the current bar is the smallest in height.

3. Steps:
   - Traverse from right to left to fill `r[i]` (next smaller on right).
   - Traverse from left to right to fill `l[i]` (next smaller on left).
   - Width = r[i] - l[i] - 1
   - Area = height[i] * width
   - Track the maximum area.

------------------------------------------------------------

Time Complexity:
----------------
O(N) 
- Each element is pushed and popped at most once from the stack.

Space Complexity:
-----------------
O(N) 
- For stacks and left/right boundary arrays.

*/


class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int maxArea = 0, curArea;
        vector<int> r(n); // next smaller element on right
        vector<int> l(n); // next smaller element on left
        stack<int> s;

        // Find next smaller to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && h[s.top()] >= h[i])
                s.pop();
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Find next smaller to the left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && h[s.top()] >= h[i])
                s.pop();
            l[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Calculate max area
        for (int i = 0; i < n; i++) {
            int width = r[i] - l[i] - 1;
            curArea = h[i] * width;
            maxArea = max(maxArea, curArea);
        }

        return maxArea;
    }
};


