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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        
        int index1 = 1;
        int index2 = 1;
        unordered_map<int, ListNode*> ump_lt;
        unordered_map<int, ListNode*> ump_gte;
        ListNode* curr = head;

        while (curr) {
            if (curr->val >= x) ump_gte[index2++] = curr;
            else ump_lt[index1++] = curr;
            curr = curr->next;
        }
        ump_lt[index1] = NULL;
        ump_gte[index2] = NULL;

        curr = new ListNode(-300);
        head = curr;
        for (int i=1; i<index1; i++) {
            curr->next = ump_lt[i];
            curr = curr->next;
        }

        for (int i=1; i<index2; i++) {
            curr->next = ump_gte[i];
            curr = curr->next;
        }

        curr->next = NULL;
        return head->next;
        
    }
};