/*
Problem Statement:
------------------
You are given an array `nums` and an integer `k`. 
Return the maximum value in every contiguous subarray (sliding window) of size `k`.

Example:
--------
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

------------------------------------------------------------
Approach: Monotonic Deque
-------------------------
- Use a deque to store elements of the current window in decreasing order.
- For each element nums[j]:
  1. Pop elements from the back of deque if they are smaller than nums[j]
     (they can never be the max again).
  2. Push nums[j] to the back of deque.
  3. If window size == k:
     - The maximum is at the front of deque.
     - Push dq.front() to result.
     - If dq.front() == nums[i] (the outgoing element), pop it from deque.
     - Slide the window by incrementing i.

Time Complexity: O(N)
- Each element is pushed and popped from the deque at most once.

Space Complexity: O(K)
- Deque stores at most K elements (indices of current window).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int i = 0, n = nums.size();

        for (int j = 0; j < n; j++) {
            // Maintain decreasing order in deque
            while (!dq.empty() && nums[j] > dq.back())
                dq.pop_back();

            dq.push_back(nums[j]);

            // Check if window size reached
            if (j - i + 1 == k) {
                res.push_back(dq.front());

                // Remove element going out of window
                if (dq.front() == nums[i])
                    dq.pop_front();
                i++;
            }
        }
        return res;
    }
};
