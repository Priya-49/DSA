// Problem: Max Chunks To Make Sorted (Leetcode-769)
// Given an array a[] of size n (a permutation of [0, 1, ..., n-1]),
// find the maximum number of chunks so that sorting each chunk individually
// and concatenating them results in a fully sorted array.


// Optimal solution: O(n) time, O(1) space
// Idea: Keep track of the maximum element seen so far. Whenever max_so_far == current index,
// we can make a chunk here.
// Explanation:
// - maxSoFar tracks the largest element encountered in the current traversal.
// - If maxSoFar equals the current index, it means all elements in this segment
//   are less than or equal to their correct positions in the sorted array.
// -Hence a chunk can be formed
int maxChunksToSorted(vector<int>& a) {
    int n = a.size();
    int maxSoFar = INT_MIN;
    int chunks = 0;
    for(int i = 0; i < n; i++) {
        maxSoFar = max(maxSoFar, a[i]); // track max in current chunk
        if(maxSoFar == i) {            // can form a chunk
            chunks++;
        }
    }
    return chunks;
}
