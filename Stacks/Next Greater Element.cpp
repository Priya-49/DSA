/*
Problem Statement:
------------------
Given an array arr[ ] of size N having distinct elements, 
the task is to find the next greater element for each element of the array 
in order of their appearance in the array. 
The next greater element for an element x is the first greater element 
on the right side of x in the array. 
If no greater element exists, output -1 for that element.

Example:
--------
Input: arr[] = [4, 5, 2, 25]
Output: [5, 25, 25, -1]

------------------------------------------------------------

Approach:
---------
1. Traverse the array from right to left.
2. Maintain a stack to keep track of "potential next greater elements".
3. For each element:
   - While stack is not empty and the top of the stack is smaller or equal 
     to the current element, pop from the stack.
   - If stack becomes empty, no greater element exists → store -1.
   - Else, the top of the stack is the next greater element.
4. Push the current element onto the stack.
5. Continue until all elements are processed.

------------------------------------------------------------

Time Complexity:
----------------
O(N) 
- Each element is pushed and popped at most once from the stack.

Space Complexity:
-----------------
O(N)
- Stack and result array store up to N elements.
*/


class Solution {
public:
    vector<int> nextLargerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return result;
    }
};
