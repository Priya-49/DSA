/*
Problem Statement:
------------------
Given an array of positive integers `nums` and an integer `k`, 
return the number of contiguous subarrays where the product of all 
the elements in the subarray is strictly less than `k`.

Example:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays are [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6].

Approach:
---------
1. Use a sliding window approach with two pointers (i, j).
2. Initialize product `p = 1`, count `c = 0`.
3. Extend the window by multiplying `p` with nums[j].
4. If `p >= k`, shrink the window from the left (i++) until `p < k`.
5. Add `(j - i + 1)` to the count for the number of valid subarrays ending at j.

Time Complexity: O(n)
-------------------
Each element is visited at most twice (once by j and once by i), so linear.

Space Complexity: O(1)
----------------------
Only a few variables are used, no extra data structures needed.
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, c = 0, p = 1, n = nums.size();
        for (int j = 0; j < n; j++) {
            p *= nums[j];
            while (i <= j && p >= k) {
                p /= nums[i];
                i++;
            }
            c += (j - i + 1);
        }
        return c;
    }
};

