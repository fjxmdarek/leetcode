/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Anshead = new ListNode();
        ListNode* Ans = Anshead;
        int tran = 0;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + tran;
            tran = tmp / 10;
            Ans->next = new ListNode(tmp % 10);
            Ans = Ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int tmp = l1->val + tran;
            tran = tmp / 10;
            Ans->next = new ListNode(tmp % 10);
            Ans = Ans->next;
            l1 = l1->next;
        }
        while (l2) {
            int tmp = l2->val + tran;
            tran = tmp / 10;
            Ans->next = new ListNode(tmp % 10);
            Ans = Ans->next;
            l2 = l2->next;
        }
        if (tran) {
            Ans->next = new ListNode(tran);
        }
        return Anshead->next;
    }
};
