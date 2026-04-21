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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *tmp = (list1->val >= list2->val) ? list2 : list1;
        ListNode *Ans = tmp;

        if (list1->val >= list2->val) {
            list2 = list2->next;
        } else {
            list1 = list1->next;
        }

        while (list1 && list2) {
            if (list1->val >= list2->val) {
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            } else {
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;
            }
        }

        if (list1) {
            tmp->next = list1;
        } else {
            tmp->next = list2;
        }

        return Ans;
    }
};
