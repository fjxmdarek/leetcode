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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head; 
        while((fast != nullptr) && (fast->next != nullptr)) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
    return nullptr;
    }
};
/*设：

链表头到环入口的距离 = a
环入口到相遇点的距离 = b
相遇点回到环入口的距离 = c
相遇时：

slow 走了 a + b
fast 走了 a + b + c + b（多绕了一圈）
fast = 2 × slow，所以：

a + b + c + b = 2(a + b)
a = c
a == c，即"头到入口的距离"等于"相遇点到入口的距离"。

所以把一个指针重置到 head，两个同速走，走 a 步后必然在入口相遇。*/