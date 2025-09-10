/*
Problem Statement:
------------------
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: nums = [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

------------------
Approach 1: Global Set to Track Duplicate Permutations
------------------------------------------------------
- Generate all permutations using swapping.
- Store each permutation in a global set<vector<int>>.
- Only insert into result vector if the permutation has not been seen before.

Time Complexity: O(n! * log(k) * n) where k is the number of unique permutations
Space Complexity: O(n! * n) for the set storing permutations
*/

class SolutionGlobalSet {
public:
    set<vector<int>> s;

    void getperm(int idx, vector<int> &a, vector<vector<int>> &res) {
        if (idx == a.size()) {
            if (s.find(a) == s.end()) {
                res.push_back(a);
                s.insert(a);
            }
            return;
        }
        for (int i = idx; i < a.size(); i++) {
            swap(a[idx], a[i]);
            getperm(idx + 1, a, res);
            swap(a[idx], a[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        getperm(0, nums, res);
        return res;
    }
};

/*
Approach 2: Swapping + Per-depth Unordered Set
---------------------------------------------
- Sort the array first to group duplicates.
- Use swapping to generate permutations.
- At each recursion depth, maintain an unordered_set to track numbers already placed at this index.
- Skip numbers already used at this depth to avoid duplicate permutations.

Time Complexity: O(n! * n) in worst case (unique permutations)  
Space Complexity: O(n) recursion stack + O(n) unordered_set at each depth
*/


class SolutionSwapping {
public:
    void getperm(int idx, vector<int> &a, vector<vector<int>> &res) {
        if (idx == a.size()) {
            res.push_back(a);
            return;
        }
        unordered_set<int> s;  // track numbers used at this depth
        for (int i = idx; i < a.size(); i++) {
            if (s.count(a[i])) continue;  // skip duplicates at this depth
            s.insert(a[i]);              // insert BEFORE swap
            swap(a[idx], a[i]);
            getperm(idx + 1, a, res);
            swap(a[idx], a[i]);           // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        getperm(0, nums, res);
        return res;
    }
};

