/*
Problem Statement:
------------------
(This is LeetCode Problem 1095: Find in Mountain Array)

You are given a mountain array `MountainArray` interface:
- int get(int index) -> returns the element at index.
- int length() -> returns the size of the array.

A mountain array is defined as:
- nums.length >= 3
- There exists an index `peak` such that:
    nums[0] < nums[1] < ... < nums[peak] 
    and 
    nums[peak] > nums[peak+1] > ... > nums[n-1].

You need to find the smallest index of the target element `t` in the mountain array.
If it does not exist, return -1.

Example:
--------
Input: target = 3, arr = [1,2,3,4,5,3,1]
Output: 2

Input: target = 3, arr = [0,1,2,4,2,1]
Output: -1

Approach:
---------
1. **Find Peak Element:**
   - Use binary search to find the index of the peak element (the maximum element).
   - Compare neighbors to move search left or right.
2. **Binary Search (Ascending part):**
   - Perform binary search in range [0, peak] in ascending order.
   - If found, return index.
3. **Binary Search (Descending part):**
   - If not found in ascending part, perform binary search in range [peak, n-1] in descending order.
4. Return -1 if not found.

Time Complexity:
----------------
- Finding peak: O(log n)
- Binary search twice: O(log n)
- Total: O(log n)

Space Complexity:
-----------------
- O(1), only constant extra space used.
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &a) {
        int n = a.length();
        int peakIdx = peak(a);

        // Search in ascending part
        int res = bin_search(a, 0, peakIdx, t, true);
        if (res != -1) return res;

        // Search in descending part
        return bin_search(a, peakIdx, n - 1, t, false);
    }

private:
    // Find peak index
    int peak(MountainArray &a) {
        int n = a.length();
        if (a.get(0) > a.get(1)) return 0;
        if (a.get(n - 1) > a.get(n - 2)) return n - 1;

        int l = 1, h = n - 2;
        while (l <= h) {
            int m = l + (h - l) / 2;
            int m1 = a.get(m - 1), m2 = a.get(m), m3 = a.get(m + 1);

            if (m2 > m1 && m2 > m3)
                return m;
            if (m1 > m3)
                h = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }

    // Binary search (acs = true → ascending order, acs = false → descending order)
    int bin_search(MountainArray &a, int l, int h, int t, bool acs) {
        while (l <= h) {
            int m = l + (h - l) / 2;
            int val = a.get(m);

            if (val == t) return m;
            else if (val > t) {
                if (acs) h = m - 1;
                else l = m + 1;
            } else {
                if (acs) l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};
