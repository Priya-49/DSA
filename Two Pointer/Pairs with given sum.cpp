/*
Problem Statement:
Given an array arr[] of integers and an integer target t,
return the number of pairs (i, j) such that arr[i] + arr[j] = t 
and i != j.

Examples:
Input: arr = [-1, 1, 5, 5, 7], t = 6
Output: 3  (pairs: {1,5}, {1,5}, {-1,7})

Input: arr = [1, 1, 1, 1], t = 2
Output: 6  (all possible distinct pairs)

------------------------------------------------------------
Approach 1: Two Pointer (for Sorted Array)
- Initialize two pointers i=0, j=n-1.
- While i<j:
   * If arr[i]+arr[j]==t:
       - Count duplicates of arr[i] and arr[j].
       - If arr[i]==arr[j], use combination formula c1*(c1-1)/2.
       - Else, add c1*c2 to result.
   * Else adjust pointers based on sum.
- Time: O(n), Space: O(1).

Approach 2: Hash Map (for Unsorted Array)
- Use a hash map to store frequency of elements.
- For each arr[i], check if (t - arr[i]) is already in map.
- If yes, add its frequency to result.
- Update map[arr[i]]++.
- Time: O(n), Space: O(n).
------------------------------------------------------------
*/

class Solution {
public:
    // Approach 1: Two Pointer (Sorted array)
    long long countPairsSorted(vector<int>& a, int t) {
        int i = 0, j = a.size() - 1;
        long long c = 0;

        while (i < j) {
            if (a[i] + a[j] == t) {
                long long c1 = 0, c2 = 0;
                int n1 = a[i], n2 = a[j];

                while (i <= j && a[i] == n1) { c1++; i++; }
                while (j >= i && a[j] == n2) { c2++; j--; }

                if (n1 == n2) c += (c1 * (c1 - 1)) / 2;
                else c += (c1 * c2);
            }
            else if (a[i] + a[j] > t) j--;
            else i++;
        }
        return c;
    }

    // Approach 2: Hash Map (Unsorted array)
    long long countPairsUnsorted(vector<int>& a, int t) {
        unordered_map<int, int> m;
        long long c = 0;

        for (int num : a) {
            if (m.count(t - num)) c += m[t - num];
            m[num]++;
        }
        return c;
    }
};

