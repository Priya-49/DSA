/*
Approach 2: Stack-Based Elimination (Optimized)
-----------------------------------------------
1. Push all people onto a stack.
2. Pop two people at a time and compare:
   - If i knows j → i cannot be celebrity → push j back.
   - Else → j cannot be celebrity → push i back.
3. After this elimination process, only one candidate remains on the stack.
4. Verification (last for loop):
   - Check every other person i:
     a) M[i][celeb] == 1 → everyone should know celeb
     b) M[celeb][i] == 0 → celeb should know no one
   - If any check fails, return -1. Otherwise, return the celebrity index.

Time Complexity: O(N)
Space Complexity: O(N) (stack)
*/

class Solution {
public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> st;

        // Push all people onto stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int i = st.top(); st.pop();
            int j = st.top(); st.pop();

            if (M[i][j] == 0)
                st.push(i); // i might be celeb
            else
                st.push(j); // j might be celeb
        }

        int celeb = st.top();

        // Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != celeb && (M[i][celeb] == 0 || M[celeb][i] == 1))
                return -1;
        }

        return celeb;
    }
};