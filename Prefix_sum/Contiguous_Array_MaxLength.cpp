/*
Problem: (Leetcode-525)
Contiguous Array - Find the maximum length of a contiguous subarray with equal number of 0s and 1s.

Approach: Prefix Sum + HashMap

Idea:
- Treat 0 as -1 and 1 as 1.
- Compute the running sum while iterating through the array.
- Use a hash map to store the **first index** of each running sum.
- If the same running sum appears again, it means the subarray between the two indices has equal number of 0s and 1s.
- Update the maximum length accordingly.

Time Complexity:
- O(n), where n = size of input array

Space Complexity:
- O(n) for storing prefix sums in the hash map
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;           // running sum
        int maxLength = 0;     // maximum length of valid subarray
        unordered_map<int,int> prefixMap;
        prefixMap[0] = -1;     // handle sum=0 from start

        for(int i = 0; i < n; i++){
            // Convert 0 to -1 to track balance between 0s and 1s
            if(nums[i] == 1)
                sum++;
            else
                sum--;

            if(prefixMap.find(sum) != prefixMap.end()) {
                // current sum seen before → subarray between previous index+1 and i is valid
                maxLength = max(maxLength, i - prefixMap[sum]);
            } else {
                // first time seeing this sum → store index
                prefixMap[sum] = i;
            }
        }

        return maxLength;
    }
};

/**
 * Usage:
 * vector<int> nums = {0,1,0,1,1,0};
 * Solution obj;
 * int result = obj.findMaxLength(nums);  // Output: 6
 */
