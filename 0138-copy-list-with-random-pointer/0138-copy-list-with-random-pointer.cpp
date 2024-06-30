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
        unordered_map<Node*, Node*> ump;
        Node* starter = new Node(0);

        Node* curr = head;
        while (curr) {
            ump[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            ump[curr]->next = ump[curr->next];
            ump[curr]->random = ump[curr->random];
            curr = curr->next;
        }
        return ump[head];
    }
};