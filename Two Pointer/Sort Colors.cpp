/*
    Problem: Sort Colors (LeetCode 75) - Dutch National Flag Problem

    Task:
    Given an array nums[] with n objects colored red (0), white (1), or blue (2),
    sort them in-place so that objects of the same color are adjacent, in the order 0, 1, 2.

    Approach (Dutch National Flag Algorithm):
    - Use three pointers:
        l -> boundary for 0's (left side)
        r -> boundary for 2's (right side)
        i -> current index scanning the array
    - Traverse while i <= r:
        * If nums[i] == 0:
              Swap nums[i] with nums[l], move both i and l forward.
        * If nums[i] == 2:
              Swap nums[i] with nums[r], move r backward.
              (Do not increment i immediately, because swapped value needs checking.)
        * If nums[i] == 1:
              Just move i forward.

    Why it works:
    - l ensures everything before it is 0.
    - r ensures everything after it is 2.
    - i explores the unknown region until array is partitioned.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), i = 0, l = 0, r = n - 1;
        while(i <= r){
            if(nums[i] == 0){
                swap(nums[l], nums[i]);
                l++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[r], nums[i]);
                r--;
            }
            else{
                i++;
            }
        }
    }
};

