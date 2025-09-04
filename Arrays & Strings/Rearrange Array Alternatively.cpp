/*
Problem Statement:
------------------
Given a sorted array of size n, rearrange the elements alternately such that:
- The first element is the maximum,
- The second element is the minimum,
- The third is the second maximum,
- The fourth is the second minimum, and so on.

Example:
---------
Input:  arr[] = {1, 2, 3, 4, 5, 6}
Output: arr[] = {6, 1, 5, 2, 4, 3}

------------------------------------------------------------
Approach 1: Using Extra Space
-----------------------------
1. Copy the array into a temporary array.
2. Use two pointers: start = 0, end = n-1.
3. Fill the original array alternately from end (max) and start (min).

Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------------------------
Approach 2: In-Place (Optimal)
-------------------------------
- Encode two numbers at one index to avoid extra space.
- maxElement = arr[n-1] + 1
- For even indices, store max element:
  arr[i] += (arr[maxIdx] % maxElement) * maxElement
- For odd indices, store min element:
  arr[i] += (arr[minIdx] % maxElement) * maxElement
- Divide all elements by maxElement to get final rearranged array

Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 2: In-place rearrangement
    void rearrangeArray(vector<int> &arr) {
        int n = arr.size();
        int maxIdx = n - 1, minIdx = 0;
        int maxElement = arr[n - 1] + 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                arr[i] += (arr[maxIdx] % maxElement) * maxElement;
                maxIdx--;
            } else {
                arr[i] += (arr[minIdx] % maxElement) * maxElement;
                minIdx++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] /= maxElement;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    sol.rearrangeArray(arr);

    cout << "Rearranged Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
