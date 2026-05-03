/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> randompoint;
        Node *travel = head;
        while(travel != nullptr) {
            Node* newNode = new Node(travel->val);
            randompoint[travel] = newNode;
            travel = travel -> next;
        }
        travel = head;
        while(travel != nullptr) {
            Node *now = randompoint[travel];
            now->next = travel->next ? randompoint[travel->next] : nullptr;
            now->random = travel->random ? randompoint[travel->random] : nullptr;
            travel = travel -> next;
        }
        return randompoint[head];
    }
};
