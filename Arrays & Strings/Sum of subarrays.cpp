// Problem: Sum of all subarrays
// Given an integer array a[], calculate the sum of all possible subarrays.

// Optimized brute-force: O(n^2) time, O(1) space
int sumSubarraysOptimized(vector<int>& a) {
    int n = a.size();
    int total = 0;
    for(int s = 0; s < n; s++) {
        int subSum = 0;
        for(int e = s; e < n; e++) {
            subSum += a[e];
            total += subSum;
        }
    }
    return total;
}

// Optimal approach using contribution formula: O(n) time, O(1) space
// Explanation: For each element a[i], it appears in (i+1)*(n-i) subarrays.
// Multiply by a[i] to get its total contribution to all subarrays.
// Example: a = [1,2,3], n = 3
// a[0]=1 appears in 1*3=3 subarrays ([1],[1,2],[1,2,3]) => contribution = 1*3=3
// a[1]=2 appears in 2*2=4 subarrays ([1,2],[2],[2,3],[2,3,4]) => contribution = 2*4=8
// a[2]=3 appears in 3*1=3 subarrays ([1,2,3],[2,3],[3]) => contribution = 3*3=9
// Total sum = 3+8+9=20
int sumSubarraysOptimal(vector<int>& a) {
    int n = a.size();
    long long total = 0;
    for(int i = 0; i < n; i++) {
        total += 1LL * a[i] * (i + 1) * (n - i);
    }
    return (int)total;
}

