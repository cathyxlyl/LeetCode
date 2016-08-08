/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ((head == NULL) or (head->next == NULL))
        {
            return NULL;
        }
        
        int m = 1;
        ListNode* lc;
        lc = head->next;
        while (lc != NULL)
        {
            m++;
            lc = lc->next;
        }
        if (n == m)
        {
            return head->next;
        }
        
        lc = head;
        int i = 0;
        while (i < m - n - 1)
        {
            lc = lc->next;
            i++;
        }
        lc->next = lc->next->next;
        return head;
    }
};
