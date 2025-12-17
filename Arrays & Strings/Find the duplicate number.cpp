/*
LeetCode 287: Find the Duplicate Number
---------------------------------------
Problem Statement:
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
but it could be repeated more than once. Return this duplicate number.

Constraints:
- You must not modify the array (or only modify it temporarily).
- You must use only constant extra space.
- Runtime complexity must be better than O(n^2).

Approach 1: Sorting
- Sort the array.
- Scan linearly to check if any consecutive elements are equal.
Time Complexity: O(n log n)
Space Complexity: O(1) or O(n) depending on sorting algorithm.
--------------------------------------------------------------------------------
Approach 2: Hashing
- Use a hash set to track visited numbers.
- If a number repeats, return it.
Time Complexity: O(n)
Space Complexity: O(n)
--------------------------------------------------------------------------------

Approach 3: Floyd’s Cycle Detection (Tortoise & Hare) → OPTIMAL
- Treat the array as a linked list where nums[i] points to nums[nums[i]].
- Because there is a duplicate, a cycle must exist.
- Use slow & fast pointers to detect the cycle.
- Once they meet, move one pointer to start and move both 1 step at a time.
- The meeting point gives the duplicate number.
Time Complexity: O(n)
Space Complexity: O(1)
--------------------------------------------------------------------------------
*/

// ---------------- Floyd's Cycle Detection (Optimal) ----------------
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entrance of cycle = duplicate number
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/*
Explanation of Optimal Approach with Example:
nums = [1,3,4,2,2]

Think of it as a linked list:
Index: 0 → 1 → 3 → 2 → 4 → 2 ...
Value: 1    3    2    4    2

- slow moves 1 step: 1 → 3 → 2 → 4
- fast moves 2 steps: 1 → 2 → 2 → 2
They meet at index with value 2 (cycle detected).
Reset slow to nums[0], move both one step:
slow = 1 → 3 → 2
fast = 2 → 2 → 2
They meet at 2 → duplicate found.
*/

//--------------C#------------
public class Solution {
    public int FindDuplicate(int[] nums) {
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
}
