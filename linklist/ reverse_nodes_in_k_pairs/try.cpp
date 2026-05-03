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
    ListNode* findlastnode(ListNode* head , int k) {
        ListNode* Ans = head;
        while(Ans && (--k)) Ans = Ans->next;
        if(k>0) return nullptr;
        else return Ans;
    }

    ListNode* reversenode(ListNode* beforehead , ListNode* head , ListNode* tail) {
        beforehead->next = tail;
        ListNode *back = head , *front = head->next;
        while(front != tail){
            ListNode *tmp = front->next;
            front->next = back;
            back = front;
            front = tmp;
        }
        return back;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first = head;
        ListNode* beforehead = new ListNode(0, head);
        ListNode *dum = beforehead;
        while(ListNode* tail = findlastnode(first , k)){
            ListNode *second_to_last = reversenode(beforehead , first , tail);
            beforehead = first;
            first = tail->next;
            tail->next = second_to_last;
        }
        return dum->next;
    }
};
