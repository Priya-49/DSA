/*
Problem Statement:
------------------
Given an array 'nums' and an integer 'k', find the maximum element 
in every sliding window of size 'k' moving from left to right.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Approach:
---------
- Use a deque to store **potential maximum elements** in the current window.
- For every new element nums[j]:
    1. Remove all elements from the back of deque which are smaller than nums[j].
    2. Push nums[j] to the back of deque.
    3. When the window size reaches k:
        - The front of deque is the current maximum; add it to the result.
        - If the front equals nums[i] (element going out of the window), pop it.
        - Slide the window by incrementing i.

Time Complexity: O(n) 
  - Each element is pushed and popped from deque at most once.
Space Complexity: O(k) 
  - Deque stores at most k elements.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int i = 0, n = nums.size();

        for(int j = 0; j < n; j++) {
            // Remove smaller elements from back
            while(!dq.empty() && nums[j] > dq.back())
                dq.pop_back();

            dq.push_back(nums[j]);

            // If window is full
            if(j - i + 1 == k) {
                res.push_back(dq.front());

                // Remove the element leaving the window
                if(dq.front() == nums[i])
                    dq.pop_front();

                i++;
            }
        }

        return res;
    }
};
