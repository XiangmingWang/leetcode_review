//https://leetcode.com/problems/add-two-numbers/
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
        int c = 0;
        ListNode* result = new ListNode(-1);
        ListNode* now = result;
        int tmp;
        while (l1 && l2) {
            tmp = l1->val + l2->val + c;
            c = tmp / 10;
            now->next = new ListNode(tmp % 10);
            now = now->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            tmp = l1->val + c;
            c = tmp / 10;
            now->next = new ListNode(tmp % 10);
            now = now->next;
            l1 = l1->next;
        }
        while (l2) {
            tmp = l2->val + c;
            c = tmp / 10;
            now->next = new ListNode(tmp % 10);
            now = now->next;
            l2 = l2->next;
        }
        if (c > 0) {
            now->next = new ListNode(c);
        }
        return result->next;
    }
};
