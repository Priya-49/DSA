/*
Problem Statement:
------------------
Given a binary array 'nums' (containing only 0s and 1s) and an integer 'k',
find the maximum length of a contiguous subarray that contains at most 'k' zeros.

Example:
Input: nums = [1,1,0,0,1,1,1,0,1], k = 2
Output: 6
Explanation: Replace at most 2 zeros with 1s to get the longest subarray of 1s.

Approach 1: Brute-force (Two Outer Loops)
------------------------------------------
This is a simple but inefficient way to solve the problem:
1. Use two loops to generate all possible subarrays.
2. Count the number of zeros in each subarray.
3. If the zeros <= k, update the maximum length.
4. Time complexity is high (O(n^2)), but easy to understand.

Approach 2: Sliding Window (Optimized)
---------------------------------------
This problem is similar to finding the maximum length substring with at most 'k' zeros:
1. Use the sliding window technique to maintain a window [i, j] containing at most 'k' zeros.
2. Expand the window by moving 'j' forward.
3. Count zeros in the window. If zeros > k, shrink the window from the left (i++) until zeros <= k.
4. Update the maximum length at each step.
Time Complexity: O(n)
Space Complexity: O(1)

*/


    // Approach 2: Sliding Window
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j;
        int zerosCount = 0;
        int maxLength = INT_MIN;

        for (j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) zerosCount++;

            if (zerosCount <= k) {
                maxLength = max(maxLength, j - i + 1);
            } else {
                while (zerosCount > k) {
                    if (nums[i++] == 0) zerosCount--;
                }
            }
        }

        return maxLength == INT_MIN ? 0 : maxLength;
    }
};


