/*
Problem: (leetcode 167)
Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers 'numbers' that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. 
Return the indices of the two numbers as a vector [index1, index2] of length 2, where 1 <= index1 < index2 <= numbers.size().

You may assume that each input has exactly one solution, and you may not use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: numbers[1] + numbers[2] = 2 + 7 = 9

Approach:
- Brute Force: Check all pairs → O(n^2) time, O(1) space.
- Optimized (Two Pointers): Start from both ends, move pointers based on sum → O(n) time, O(1) space.

1. Use two pointers: start (i = 0) and end (j = n-1).
2. While i < j:
   - If numbers[i] + numbers[j] > target → decrement j.
   - If numbers[i] + numbers[j] < target → increment i.
   - Else → found the pair, return [i+1, j+1].

Time Complexity: O(n) — single pass with two pointers.
Space Complexity: O(1) — only a small vector of size 2 is used.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> result;

        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum > target)
                j--;
            else if(sum < target)
                i++;
            else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
        return result;
    }
};
