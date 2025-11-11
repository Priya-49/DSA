/*
Problem: 3Sum
Find all unique triplets in the array that sum to zero.

------------------------------------------
🔹 Approach 1: Brute Force (O(n³))
- Check every possible triplet (i, j, k) using three nested loops.
- If nums[i] + nums[j] + nums[k] == 0, store it in a set to avoid duplicates.
- Very inefficient for large inputs.

------------------------------------------
🔹 Approach 2: Hashing + Set (O(n²))
- Fix one element (nums[i]).
- Use an unordered_set to find pairs in the remaining array that sum up to -nums[i].
- Store triplets in a set to avoid duplicates.
- Better than brute force but still requires extra space.

------------------------------------------
🔹 Approach 3: Two-Pointer (Optimal) (O(n²))
brief it Intuition:
1. **Sorting helps simplify the problem**:
   Once the array is sorted, you can fix one element and find the remaining two
   using a two-pointer approach (similar to the two-sum problem).

2. **Core idea**:
   - Fix one number `nums[i]` as the first element of the triplet.
   - Use two pointers:
        - `l` (left) starts from `i + 1`
        - `r` (right) starts from `n - 1`
   - Calculate `s = nums[i] + nums[l] + nums[r]`.
        - If `s < 0`, increase `l` to get a larger sum.
        - If `s > 0`, decrease `r` to get a smaller sum.
        - If `s == 0`, record the triplet and move both pointers inward.

3. **Avoid duplicates**:
   - Skip duplicate values for `i` (so same first element is not re-used).
   - After finding a valid triplet, skip duplicate values for `l` (second element).

------------------------------------------
Example:
nums = [-1, 0, 1, 2, -1, -4]
Sorted → [-4, -1, -1, 0, 1, 2]
Triplets → [-1, -1, 2], [-1, 0, 1]

------------------------------------------
Time Complexity:  O(n²)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];

                if (s < 0) l++;
                else if (s > 0) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    // Skip duplicates for the second element
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }

        return ans;
    }
};
