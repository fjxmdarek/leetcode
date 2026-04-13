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
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        int len = 0;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
            len++;
        }
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (nums[i] != nums[j]) return false;
        }
        return true;
    }
};
