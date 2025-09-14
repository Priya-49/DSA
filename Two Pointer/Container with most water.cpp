/*
    Problem: Container With Most Water (LeetCode 11)

    Task:
    Given an array h[] where h[i] is the height of a vertical line at index i,
    choose two lines that together with the x-axis form a container that holds
    the most water. Return the maximum area.

    Approach (Two Pointers):
    - Start with two pointers at the ends (i = 0, j = n-1).
    - The area formed by i and j is (j - i) * min(h[i], h[j]).
    - To potentially find a larger area, move the pointer at the shorter line inward:
        - If h[i] < h[j], increment i; else decrement j.
      This is because moving the taller line cannot increase the limiting height,
      while moving the shorter one might find a taller line.

    Correctness intuition:
    - Width shrinks as pointers move inward, so only an increase in the limiting height
      (the smaller of the two) can compensate and yield a larger area.
    - Hence, always discard the shorter side.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/


class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size(),i=0,j=n-1,ma=0;
        while(i<j){
            ma=max(ma,(j-i)*min(h[i],h[j]));
            h[i]<h[j]?i++:j--;
        }
        return ma;
    }
};

