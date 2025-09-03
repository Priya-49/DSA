/*
LeetCode 442: Find All Duplicates in an Array
-------------------------------------------
Problem Statement:
Given an array of integers nums of length n where 1 ≤ nums[i] ≤ n, some elements appear twice and others once.
Return an array of all the elements that appear twice.
You must solve the problem without extra space and in O(n) runtime (modifying the input array is allowed).

Approach: Negative Marking (Optimal)
-----------------------------------
- For each number x in nums, go to index abs(x) - 1.
- If the value at that index is negative, x is a duplicate.
- Otherwise, negate the value at that index to mark it visited.
- Continue for all elements.
- Add duplicates to result array.

Time Complexity: O(n)
Space Complexity: O(1) (modifies input array)
*/



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) result.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return result;
    }
};

