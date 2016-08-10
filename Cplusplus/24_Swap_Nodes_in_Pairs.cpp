/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* init;
        ListNode* pre;
        ListNode* ln1;
        ListNode* ln2;
        ListNode* aft;
        
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            return head;
        }
        
        init = head->next;
        
        ln1 = head;
        ln2 = head->next;
        aft = ln2->next;

        while (ln2 != NULL)
        {
            pre->next = ln2;
            ln2->next = ln1;
            ln1->next = aft;
            
            if ((aft == NULL) || (aft->next == NULL))
            {
                break;
            }
            else 
            {
                pre = ln1;
                ln1 = aft;
                ln2 = aft->next;
                aft = ln2->next;
            }
        }
        return init;
    }
};
