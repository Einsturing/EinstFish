//难度-中等
//链表模拟
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(head == nullptr) {
            node->next = node;
            return node;
        }
        if(head->next == head) {
            head->next = node;
            node->next = head;
            return head;
        }
        Node* cur = head;
        Node* next = head->next;
        while(next != head) {
            if(insertVal >= cur->val && insertVal <= next->val) break;
            if(cur->val > next->val) if(insertVal > cur->val || insertVal < next->val) break;
            cur = cur->next;
            next = next->next;
        }
        cur->next = node;
        node->next = next;
        return head;
    }
};