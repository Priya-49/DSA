/*
Problem Statement:
------------------
Given an array 'a' of size n representing the number of pages in n books, and an integer k representing the number of students.  
The task is to allocate books to students such that:
1. Each student gets at least one book.
2. Books allocated to a student are consecutive.
3. The maximum number of pages assigned to a student is minimized.

Return the minimum possible maximum pages a student can get.  
Return -1 if the number of students is greater than the number of books.

Example:
Input: a = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocate first 2 books to student 1 (12+34=46) and last 2 books to student 2 (67+90=157).  
The maximum pages assigned = min(46,157) = 113 (minimum possible maximum).

Approach:
---------
1. Use binary search on the answer:
   - Left bound `l = 0`, right bound `r = sum of all pages`.
2. For each mid value `m`, check if it is possible to allocate books such that maximum pages for any student <= m using `isValid`.
3. If valid, try a smaller value by setting `r = m - 1`.
4. Otherwise, try a larger value by setting `l = m + 1`.
5. Return the minimum maximum found.

Time Complexity: O(n * log(sum of pages))  
Space Complexity: O(1) extra space (besides input array)
*/


class Solution {
public:
    int findPages(vector<int> &a, int k) {
        int l = 0, r = accumulate(a.begin(), a.end(), 0), m, ma = -1, n = a.size();
        if(k > n) return -1;

        while(l <= r){
            m = l + (r - l) / 2;
            if(isValid(a, m, k)){
                ma = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ma;
    }

    bool isValid(vector<int> a, int m, int k){
        int n = a.size(), s = 0, sd = 1;
        for(int i = 0; i < n; i++){
            if(a[i] > m) return false;
            s += a[i];
            if(s > m){
                s = a[i];
                sd++;
            }
        }
        return sd <= k;
    }
};
