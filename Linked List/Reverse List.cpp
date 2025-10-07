/*
Problem Statement:
------------------
Given the head of a singly linked list, reverse the list and return the reversed list.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

Approach:
---------
1. Initialize three pointers: 
   - prev = NULL
   - curr = head
   - next = NULL
2. Traverse the linked list:
   - Store curr->next in next.
   - Point curr->next to prev.
   - Move prev to curr.
   - Move curr to next.
3. Return prev as the new head of the reversed list.

Time Complexity: O(n) - traverse all nodes once.  
Space Complexity: O(1) - no extra space used.
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
