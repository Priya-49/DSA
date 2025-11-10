/*
Problem Statement:
Given an array `a` of integers and a number `k`, find the first negative integer
in every window (subarray) of size `k`. If a window does not contain a negative
integer, record `0` for that window.

Example:
Input: a = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output: [-1, -1, -7, -15, -15, 0]

Approach:
1. Use a sliding window of size `k`.
2. Maintain a deque to store negative elements of the current window.
3. For each new element:
   - Add it to the deque if it’s negative.
   - Once the window reaches size `k`, record the first element of the deque.
4. Before sliding the window, remove the element that is going out of range.

Time Complexity: O(N)
- Each element is added and removed from the deque at most once.

Space Complexity: O(K)
- At most `k` elements (negatives) are stored in the deque.
*/


class Solution {
public:
    vector<int> firstNegInt(vector<int>& a, int k) {
        int n = a.size(), i = 0;
        deque<int> dq;  // stores negative numbers in current window
        vector<int> v;  // result vector

        for (int j = 0; j < n; j++) {
            // If current element is negative, push it into deque
            if (a[j] < 0)
                dq.push_back(a[j]);

            // When window size becomes k
            if (j - i + 1 == k) {
                // Record the first negative element of the window
                if (!dq.empty())
                    v.push_back(dq.front());
                else
                    v.push_back(0); // No negative number in this window

                // Slide the window
                if (!dq.empty() && a[i] == dq.front())
                    dq.pop_front();
                i++;
            }
        }
        return v;
    }
};

