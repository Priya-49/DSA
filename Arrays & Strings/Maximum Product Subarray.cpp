/*
Problem: Maximum Product Subarray

Approach: Optimal Observation-Based Approach (Prefix and Suffix Product)

Intuition:
1. Subarray Product Problems:
   - Unlike sum problems (Kadane's algorithm), products are affected drastically by negatives and zeros.
2. Negative Numbers and Zeros:
   - Even number of negatives -> positive product.
   - Odd number of negatives -> negative product.
   - Zero resets the product; after a zero, start a new product calculation.
3. Prefix and Suffix Products:
   - Traverse the array left-to-right (prefix) and right-to-left (suffix).
   - Update max product at each step from both directions.
4. Why Both Directions?
   - A negative number may become maximum when combined with another negative later.
   - Single-direction traversal may miss cases where best product subarray spans a zero or ends at the far end.
5. Resetting:
   - If running product becomes zero, reset it to 1 to start fresh, ensuring subarrays after zero are considered independently.

Example:
Array: [2, -3, 4, -2, 0, 6, -2]
Left-to-right: Track product, reset at 0.
Right-to-left: Track product, reset at 0.
Max product at any step = max(left_product, right_product, current max).

Time Complexity: O(n) -> single pass from both directions
Space Complexity: O(1) -> constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1, suf = 1; // prefix and suffix running products
        int ans = INT_MIN;     // to store the max product

        for(int i = 0; i < n; i++){
            // Reset running product if zero encountered
            if(pref == 0) pref = 1;
            if(suf == 0) suf = 1;

            pref *= nums[i];         // left-to-right product
            suf *= nums[n - i - 1]; // right-to-left product

            ans = max(ans, max(pref, suf)); // update maximum
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -3, 4, -2, 0, 6, -2};
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
