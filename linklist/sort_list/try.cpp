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
    ListNode* sortList(ListNode* head) {
        ListNode* travel = head;
        multiset<int> val_table;
        unordered_map<int , ListNode*> Node_Map;
        while(travel != nullptr) {
            val_table.insert(travel->val);
            Node_Map.insert(travel->val , travel);
            travel = travel->next;
        }
        for(int x : val_table) {
            Node_Map[x]->next =
        }
    }
};
