/*
Problem Statement:
------------------
Given an array of integers nums and an integer k, 
return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), 
where the following are true:
   - 0 <= i < j < nums.length
   - |nums[i] - nums[j]| == k

Examples:
---------
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: The 2 unique pairs are (1,3) and (3,5).

Input: nums = [1,1,1,2], k = 0
Output: 1
Explanation: The only valid pair is (1,1). 
Note that duplicates should only be counted once.

----------------------------------------------------
Approach 1: HashMap (Frequency Counting)
----------------------------------------
1. Use an unordered_map to store frequencies of all elements.
2. If k == 0 → count how many elements appear more than once 
   (e.g., nums = [1,1,1,2], only (1,1) is valid).
3. If k > 0 → for each element x, check if (x + k) exists in map.
4. This guarantees unique pairs without double counting.

Edge case handled:
- k == 0 → only frequencies > 1 are valid.
- nums with duplicates → counted only once since we iterate map.

Time Complexity: O(n)
Space Complexity: O(n)

----------------------------------------------------
Approach 2: Sorting + Two Pointers
----------------------------------
1. Sort the array.
2. Use two pointers l and r.
3. If nums[r] - nums[l] < k → move r forward.
   If nums[r] - nums[l] > k → move l forward.
   If nums[r] - nums[l] == k → count the pair, then skip all duplicates.
4. Continue until both pointers reach the end.

Special Note:
- We include `if (l == r)` to handle the k == 0 case.
  Without it, the algorithm would incorrectly compare an element with itself 
  (nums[r] - nums[l] = 0 when l == r). But valid pairs require i < j.

Edge case handled:
- Skipping duplicates after counting ensures each unique pair 
  is counted once, even if multiple duplicates exist.

Time Complexity: O(n log n)   (due to sorting)
Space Complexity: O(1)        (ignoring sort space)
*/


class Solution {
public:
    // Approach 1: HashMap
    int findPairs_HashMap(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i : nums) m[i]++;  // count frequencies
        
        int c = 0;
        for(auto &p : m) {
            if(k == 0) {
                // edge case: need duplicates
                if(p.second > 1) c++;
            } else {
                // check if complement exists
                if(m.count(p.first + k)) c++;
            }
        }
        return c;
    }

    // Approach 2: Sorting + Two Pointers
    int findPairs_TwoPointer(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1, n = nums.size(), c = 0;
        while(l < n && r < n) {
                /*
                 l == r:
                   - Prevents comparing the same element with itself.
                   - Important for k == 0 case, since nums[r] - nums[l] = 0,
                */   
               if(l == r || nums[r] - nums[l] < k) {
                r++;
            } else if(nums[r] - nums[l] > k) {
                // Difference too large, move l forward to reduce the gap
                l++;
            } else {
                c++;  // Found a valid pair with difference == k
                int n1 = nums[l], n2 = nums[r];
                // Skip duplicates to count only unique pairs
                while(l < n && nums[l] == n1) l++;
                while(r < n && nums[r] == n2) r++;
            }
        }
        return c;
    }
};

