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
    ListNode* findlastnode(ListNode* head, int k) {
        ListNode* cur = head;
        while (cur && --k) {
            cur = cur->next;
        }
        return k > 0 ? nullptr : cur;
    }

    ListNode* reversenode(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* cur = head;

        while (prev != tail) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return tail;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode* beforehead = &dummy;
        ListNode* first = head;

        while (ListNode* tail = findlastnode(first, k)) {
            ListNode* next_group = tail->next;
            beforehead->next = reversenode(first, tail);
            beforehead = first;
            first = next_group;
        }

        return dummy.next;
    }
};
