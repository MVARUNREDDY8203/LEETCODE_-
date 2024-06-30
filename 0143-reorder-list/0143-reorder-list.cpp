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
    void reorderList(ListNode* head) {
        ListNode* ans = new ListNode(-1, head);
        int n = 0;
        unordered_map<int, ListNode*> ump;
        ListNode* curr = head;
        while (curr) {
            ump[n++] = curr;
            curr = curr->next;
        }

        int l = 0, r = n-1;
        curr = ans;
        while (l < r) {
            curr->next = ump[l];
            ump[l]->next = ump[r];
            curr = ump[r];
            l++;
            r--;
        }
        cout<<l<<" "<<r<<" "<<curr->val;
        if (l == r) {
            curr->next = ump[l];
            curr = curr->next;
        }
        // cout<<curr->next->val;
        curr->next = NULL;
    }
};