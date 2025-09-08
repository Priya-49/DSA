/*
Problem: Big Sorting
--------------------
You are given an array of integers, but the integers are very large.
They are provided as strings. Sort them in ascending order.

Example:
Input:
5
31415926535897932384626433832795
1
3
10
3

Output:
1
3
3
10
31415926535897932384626433832795

---------------------------------------------------
Approach:
- Since numbers are too large, store them as strings.
- Custom compare function:
    1. If lengths differ, the shorter string represents the smaller number.
    2. If lengths are equal, compare lexicographically (like dictionary order).
- Use sort with this comparator.


---------------------------------------------------
Time Complexity:
- Sorting takes O(N log N) comparisons.
- Each comparison may take O(L), where L = max length of a number.
- Overall: O(N log N * L)

Space Complexity:
- O(1) extra (in-place sort), ignoring input storage.
*/


// Comparator function
bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;   // same length → lexicographic compare
    }
    return a.length() < b.length(); // shorter number is smaller
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}

