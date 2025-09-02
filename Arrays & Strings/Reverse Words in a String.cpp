/*
Problem Statement: (Leetcode 151)
------------------
Given a string s, reverse the order of words in the string. 
A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space. 
Return a string of the words in reverse order concatenated by a single space. 
The returned string should not contain leading or trailing spaces.

Example:
Input: "  hello world  "
Output: "world hello"
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string r = ""; // Result string

        // Traverse the string from end to start
        for(int i = n - 1; i >= 0; i--) {
            string w = ""; // Temporary word

            // Build the word character by character
            while(i >= 0 && s[i] != ' ') {
                w += s[i--];
            }

            // Reverse the word since it was built in reverse order
            reverse(w.begin(), w.end());

            // Append to result if the word is not empty
            if(!w.empty()) {
                r += ' ' + w; // Add a space before the word
            }
        }

        // Remove the leading space added initially
        return r.substr(1);
    }
};

/*
Time Complexity: O(n)
- We traverse the string once and reverse each word (total characters = n).

Space Complexity: O(n)
- Space used for result string 'r' and temporary word string 'w'.
*/
