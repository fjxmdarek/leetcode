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
    void swap_nodes(ListNode* prev, ListNode* back, ListNode* front) {
        back->next = front->next;
        front->next = back;
        prev->next = front;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *back = head;
        ListNode *front = head->next;

        while (back && front) {
            swap_nodes(prev, back, front);
            prev = back;
            back = back->next;
            if (!back) {
                break;
            }
            front = back->next;
        }

        return dummy.next;
    }
};