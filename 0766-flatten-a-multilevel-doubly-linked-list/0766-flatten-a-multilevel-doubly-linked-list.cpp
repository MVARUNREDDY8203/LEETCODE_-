/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        if (head->child != nullptr) {
            Node* nextptr = head->next;
            head->next = flatten(head->child);
            head->child = nullptr;
            head->next->prev = head;
            Node* eol = head;
            while (eol->next) {
                eol = eol->next;
            }
            eol->next = nextptr;
            if (nextptr) nextptr->prev = eol;
        }
        else {
            head->next = flatten(head->next);
        }

        return head;
    }
};