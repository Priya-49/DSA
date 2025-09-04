/*
Problem Statement:
------------------
Given two arrays a[] and b[], determine if there exists a pair (x, y),
where x is from a[] and y is from b[], such that swapping x and y
makes the sum of both arrays equal.

Example:
a = [4, 1, 2, 1, 1, 2], b = [3, 6, 3, 3]
Output: true
Explanation: Swap 1 from a[] with 3 from b[] → both sums become equal.

Mathematical Formula:
---------------------
Let sumA = sum(a), sumB = sum(b)
After swapping x from a[] and y from b[]:

    newSumA = sumA - x + y
    newSumB = sumB - y + x

For sums to be equal:

    newSumA = newSumB
    sumA - x + y = sumB - y + x
    sumA - sumB = 2*(x - y)
    x - y = (sumA - sumB) / 2

So, we need to find x in a[] and y in b[] such that:

    y = x - (sumA - sumB)/2

Approach:
---------
1. Compute sumA and sumB
2. Calculate diff = sumA - sumB
   - If diff is odd → return false
   - Otherwise, look for pair satisfying y = x - diff/2
3. Use a hash set for elements of a[] for O(1) lookup
4. Loop through b[] to check if y = x - diff/2 exists
5. Return true if found, otherwise false

Time Complexity: O(n + m)
Space Complexity: O(n)
*/

class Solution {
public:
    bool findSwapValues(vector<int>& a, vector<int>& b) {
        int sumA = accumulate(a.begin(), a.end(), 0);
        int sumB = accumulate(b.begin(), b.end(), 0);
        int diff = sumA - sumB;

        if(diff % 2 != 0) return false; // no integer solution

        diff /= 2;
        unordered_set<int> s(a.begin(), a.end());

        for(int y : b) {
            if(s.count(y + diff)) return true; // valid pair found
        }

        return false;
    }
};

