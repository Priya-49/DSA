/*
Problem Statement:
------------------
You are given a list of operations (string) on a stack. The operations can be:
1 x -> Push integer x onto the stack
2   -> Pop the top element from the stack
3   -> Print the maximum element in the stack

Return the results of all type 3 operations in order.

Example:
--------
Input: ["1 97", "2", "1 20", "2", "1 26", "1 20", "2", "3", "1 91", "3"]
Output: [26, 91]

------------------------------------------------------------
Approach 1: Stack of Pairs
--------------------------
- Use stack<pair<int,int>> where:
  first = actual value
  second = max value so far
- On push: compare new value with current max
- On pop: simply pop
- On max query: return st.top().second

Time Complexity: O(N)
Space Complexity (excluding stack memory):
- For every push, we store a pair (2 values) → O(2*N)

------------------------------------------------------------
Approach 2: Encoded Max Tracking
--------------------------------
- Use a single stack<int> and track `maxVal` (current max).
- When pushing a new max element:
  - Push encoded value = 2*val - maxVal
  - Update maxVal = val
- On pop, if top > maxVal, decode the previous max.
- On max query: return `maxVal`.

Time Complexity: O(N)
Space Complexity (excluding stack memory):
- Only one extra variable `maxVal` is needed → O(1)
*/



class Solution1 {
public:
    vector<int> getMax(vector<string> op) {
        stack<pair<int,int>> st;
        vector<int> v;
        for (string s : op) {
            if (s[0] == '2') {
                st.pop();
            }
            else if (s[0] == '3') {
                v.push_back(st.top().second);
            }
            else { // push
                int n = stoi(s.substr(2));
                int maxVal = st.empty() ? n : max(n, st.top().second);
                st.push({n, maxVal});
            }
        }
        return v;
    }
};

//Approach 2

class Solution2 {
public:
    vector<int> getMax(vector<string> op) {
        stack<int> st;
        int maxVal = INT_MIN;
        vector<int> v;

        for (string s : op) {
            if (s[0] == '2') {
                if (st.top() > maxVal) {
                    // decode previous max
                    maxVal = 2 * maxVal - st.top();
                }
                st.pop();
            }
            else if (s[0] == '3') {
                v.push_back(maxVal);
            }
            else { // push
                int n = stoi(s.substr(2));
                if (st.empty()) {
                    st.push(n);
                    maxVal = n;
                }
                else {
                    if (n > maxVal) {
                        st.push(2 * n - maxVal); // encoded value
                        maxVal = n;
                    }
                    else {
                        st.push(n);
                    }
                }
            }
        }
        return v;
    }
};

