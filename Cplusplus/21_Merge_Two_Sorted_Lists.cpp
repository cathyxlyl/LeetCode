/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur;
        ListNode* head;
        int tag;
        if (l1 == NULL) 
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        
        if (l1->val <= l2->val)
        {
            cur = l1;
            head = cur;
            tag = 1;
        }
        else
        {
            cur = l2;
            head = cur;
            tag = 2;
        }
        
        while ((l1 != NULL) && (l2 != NULL))
        {
            if (tag == 1)
            {
                if (l1->next == NULL)
                {
                    cur->next = l2;
                    break;
                }
                if (cur->next->val <= l2->val)
                {
                    l1 = l1->next;
                    cur = l1;
                }
                else
                {
                    l1 = l1->next;
                    cur->next = l2;
                    cur = l2;
                    tag = 2;
                }
            }
            else
            {
                if (l2->next == NULL)
                {
                    cur->next = l1;
                    break;
                }
                if (cur->next->val <= l1->val)
                {
                    l2 = l2->next;
                    cur = l2;
                }
                else
                {
                    l2 = l2->next;
                    cur->next = l1;
                    cur = l1;
                    tag = 1;
                }
            }
        }
        return head;
    }
};
