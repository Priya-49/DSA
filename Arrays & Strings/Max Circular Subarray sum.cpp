/*
    Problem: 918. Maximum Sum Circular Subarray

    Approach:
    =========
    The maximum circular subarray sum can come from two cases:

    1. Non-wrapping subarray (normal case)
       - Use Kadane's algorithm to find the maximum subarray sum (maxKadane).

    2. Wrapping subarray
       - In circular arrays, the maximum subarray may start at the end and continue at the beginning.
       - This is equivalent to taking the total sum of the array and subtracting the "minimum subarray sum".
       - Formula: maxWrap = totalSum - minKadane.

    Final Answer:
       - If all numbers are negative, then maxWrap becomes 0 (invalid because subarray must be non-empty).
         In this case, return maxKadane directly.
       - Otherwise, answer = max(maxKadane, maxWrap).

    Edge Case:
    ==========
    - If all elements are negative:
        Example: [-3, -5, -2]
        -> Kadane's gives maxKadane = -2 (correct)
        -> totalSum = -10, minKadane = -10, maxWrap = 0
        -> Wrong to return 0 (empty subarray), so we must handle this case:
           return maxKadane.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/


class Solution {
public:
    // Standard Kadane's algorithm to find maximum subarray sum
    int kadaneMax(vector<int>& arr) {
        int cur = arr[0], maxSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            cur = max(arr[i], cur + arr[i]);
            maxSum = max(maxSum, cur);
        }
        return maxSum;
    }

    // Kadane's variation to find minimum subarray sum
    int kadaneMin(vector<int>& arr) {
        int cur = arr[0], minSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            cur = min(arr[i], cur + arr[i]);
            minSum = min(minSum, cur);
        }
        return minSum;
    }

    int circularSubarraySum(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        int maxKadane = kadaneMax(arr); // Case 1
        int minKadane = kadaneMin(arr); // For Case 2

        // Edge case: if all elements are negative
        if (maxKadane < 0) return maxKadane;

        int maxWrap = totalSum - minKadane; // Case 2
        return max(maxKadane, maxWrap);
    }
};

//----------C#-----------
public class Solution {
    public int MaxKadane(int[] nums){
        int s=0,ms=int.MinValue,n=nums.Length,i;
        for(i=0;i<n;i++){
            s+=nums[i];
            ms=Math.Max(ms,s);
            if(s<0) s=0;
        }
        return ms;
    }
    public int MinKadane(int[] nums){
        int s=0,ms=int.MaxValue,n=nums.Length,i;
        for(i=0;i<n;i++){
            if(nums[i]<nums[i]+s)
               s=nums[i];
            else
               s+=nums[i];   
            ms=Math.Min(ms,s);
        }
        return ms;
    }
    public int MaxSubarraySumCircular(int[] nums) {
        int MaxSum=MaxKadane(nums),MinSum=MinKadane(nums),n=nums.Length;
        int totalSum=nums[0..n].Sum();
        if(MaxSum<0) return MaxSum;
        return Math.Max(MaxSum,totalSum-MinSum);
    }
}

