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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, ListNode*> ump;
        ump[0] = new ListNode(0, head);
        ListNode* curr = head;
        int m = 0;
        while (curr) {
            ump[++m] = curr;
            curr = curr->next; 
        }
        ump[m+1] = NULL;
        // if (m == 1) return NULL;
        // if (ump.count(m-1))

        ump[(m-n+1)-1]->next = ump[(m-n+1)+1];

        return ump[0]->next;
    }
};