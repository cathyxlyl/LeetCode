/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        
        ListNode* pre;
        ListNode* cur;
        ListNode* aft;
        
        pre = head;
        cur = head->next;
        head->next = NULL;
        while (cur != NULL)
        {
            aft = cur->next;
            cur->next = pre;
            pre = cur;
            cur = aft;
        }
        return pre;
    }
};
