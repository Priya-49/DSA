/*
Problem:
--------
Given an integer array nums and an integer k, return the number of subarrays
that contain exactly k distinct integers.

Example:
--------
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation:
The subarrays with exactly 2 distinct integers are:
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,3]

Approach:
---------
1. To count subarrays with exactly K distinct integers, we use the formula:
   exactlyK = atMost(K) - atMost(K - 1)

2. Helper function countSubarray(nums, k) returns the number of subarrays
   with at most k distinct elements using the sliding window + hashmap technique:
   - Expand the window by moving 'j' and include nums[j].
   - If nums[j] is new to the window, increment 'distinct'.
   - If distinct > k, shrink the window from the left until valid.
   - At each step, the number of valid subarrays ending at j is (j - i + 1).

3. Finally, compute:
   subarraysWithKDistinct = countSubarray(nums, k) - countSubarray(nums, k - 1)

Time Complexity:
----------------
- O(N), where N is the size of nums.
- Each element is inserted/removed from the map at most once.

Space Complexity:
-----------------
- O(N) in the worst case for the hashmap (if all elements are distinct).

Constraints:
------------
- 1 <= nums.length <= 2 * 10^4
- 1 <= nums[i], k <= nums.length
*/



class Solution {
public:
    // Count subarrays with at most k distinct integers
    int countSubarray(vector<int>& nums, int k) {
        int i = 0, distinct = 0, count = 0;
        unordered_map<int,int> freq;

        for (int j = 0; j < nums.size(); j++) {
            if (freq[nums[j]] == 0)  // new distinct element
                distinct++;
            freq[nums[j]]++;

            while (distinct > k) {  // shrink window
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) distinct--;
                i++;
            }
            count += (j - i + 1);  // valid subarrays ending at j
        }
        return count;
    }

    // Count subarrays with exactly k distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarray(nums, k) - countSubarray(nums, k - 1);
    }
};
