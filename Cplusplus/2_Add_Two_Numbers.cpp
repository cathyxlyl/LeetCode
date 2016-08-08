/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* cur;
        ListNode* pre;
        int tmp = 0;
        bool first = true;
        while ((l1 != NULL) || (l2 != NULL) || (tmp == 1))
        {
            ListNode* ln = new ListNode(0);
            if ((l1 == NULL) && (l2 == NULL))
            {
                ln->val = tmp;
                tmp = 0;
            }
            else if (l1 == NULL)
            {
                ln->val = (l2->val + tmp) % 10;
                tmp = (l2->val + tmp) / 10;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                ln->val = (l1->val + tmp) % 10;
                tmp = (l1->val + tmp) / 10;
                l1 = l1->next;
            }
            else
            {
                ln->val = (l1->val + l2->val + tmp) % 10;
                tmp = (l1->val + l2->val + tmp) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            if (first)
            {
                res = ln;
                first = false;
                pre = res;
            }
            else
            {
                pre->next = ln;
                pre = ln;
            }
        }
        return res;
    }
};
