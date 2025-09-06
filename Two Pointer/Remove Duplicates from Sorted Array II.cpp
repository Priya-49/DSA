/*
    Problem: Remove Duplicates from Sorted Array II (LeetCode 80)

    Task:
    Given a sorted array nums[], remove duplicates in-place such that each unique element
    can appear at most twice. The relative order of the elements should be kept the same.
    Return the new length after removal.

    Approach:
    - Since the array is sorted, duplicates will always be consecutive.
    - Use a pointer `i` to keep track of the "write position".
    - Maintain a counter `c` for how many times the current number has appeared.
    - For each number nums[j]:
        - If it's the same as the previous one, increment `c`.
        - Otherwise reset `c = 1`.
        - Only copy nums[j] to nums[i] if c <= 2 (allow at most two occurrences).
        - Increment i when we keep an element.
    - Return i, which represents the new length of the array.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, c=1, j, n=nums.size();
        for(j=1; j<n; j++){
            if(nums[j] == nums[j-1])
                c++;
            else
                c=1;
            if(c <= 2){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
