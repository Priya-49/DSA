/*
Problem: Sum of Subarray Minimums

Given an integer array arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 10^9 + 7.

Example:
Input: arr = [3,1,2,4]
Output: 17
Explanation: Subarrays are [3],[1],[2],[4],[3,1],[1,2],[2,4],[3,1,2],[1,2,4],[3,1,2,4].
Minimums are 3,1,2,4,1,1,2,1,1,1. Sum = 17.

----------------------------------------------------------

Approach 1: Brute Force
  -For each starting index i, iterate all subarrays ending at j >= i
  -Keep track of the minimum in the current subarray
  -Add it to the total sum
Time complexity = O(n²), Space complexity = O(1)

 ----------------------------------------------------------

Approach 2: Stack (Optimal)

Stack Approach (Optimal):
Implementation:
1. Next Smaller or Equal elements (right)
2. Previous Smaller elements (left)
3. Contribution of each element
  -Number of subarrays where a[i] is minimum = left × right
  -left = i - l[i], right = r[i] - i
  -Multiply by 1LL to prevent overflow

   - Example (manual counting):
     arr = [1,4,6,7,3,7,8], focus on 3 (index 4)
     - Left distance = 4 (can start at indices 1,2,3,4)
     - Right distance = 3 (can end at indices 4,5,6)
     - Total subarrays where 3 is minimum = 4 × 3 = 12
     - Manual subarrays:
       [4,6,7,3], [4,6,7,3,7], [4,6,7,3,7,8]
       [6,7,3], [6,7,3,7], [6,7,3,7,8]
       [7,3], [7,3,7], [7,3,7,8]
       [3], [3,7], [3,7,8]
       
Time complexity = O(n), Space complexity = O(n)
*/


// Approach 1: Brute Force

class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMinsBrute(vector<int>& arr) {
        long long s = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int mini = INT_MAX;
            for(int j = i; j < n; j++){
                mini = min(mini, arr[j]);
                s = (s + mini) % MOD; // take modulo at each step
            }
        }

        return (int)s;
}

   
// Approach 2: Stack (Optimal)

    int sumSubarrayMins(vector<int>& a) {
        long long s = 0;
        int n = a.size();
        vector<int> r(n), l(n);
        stack<int> st;

      
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] <= a[st.top()]) st.pop();
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

      
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()]) st.pop();
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

       
        for (int i = 0; i < n; i++) {
            long long left = i - l[i];
            long long right = r[i] - i;
            s = (s + (1LL * a[i] * left * right) % MOD) % MOD;
        }

        return (int)(s % MOD);
    }
};

