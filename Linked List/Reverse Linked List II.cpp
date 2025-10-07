/*
Problem Statement:
------------------
Given the head of a singly linked list and two integers left and right where 1 ≤ left ≤ right ≤ n,  
reverse the nodes of the list from position left to position right, and return the reversed list.

Example:
Input: head = 1->2->3->4->5, left = 2, right = 4
Output: 1->4->3->2->5

Approach:
---------
1. Use a dummy node pointing to head to simplify edge cases.
2. Move a pointer `prev` to the node just before position `left`.
3. Set `current` to prev->next (start of sublist to reverse).
4. Reverse the sublist using iterative pointer manipulation:
   - For each node in the sublist, remove it and insert it right after `prev`.
5. Return dummy.next as the new head.

Time Complexity: O(n) - traverse the list once.  
Space Complexity: O(1) - only constant extra pointers used.
*/


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* current = prev->next;
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        return dummy.next;
    }
};
