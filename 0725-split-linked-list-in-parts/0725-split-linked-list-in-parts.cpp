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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        vector<int> npp(k, 0);
        int idx = 0, m = n;
        while (m > 0) {
            npp[idx % k]++;
            idx++;
            m--;
        }

        curr = head;
        vector<ListNode*> ans;
        for (auto i: npp) {
            int cnt = 1;
            ListNode* curr_head = curr;
            while (cnt < i && curr_head != nullptr) {
                curr = curr->next;
                cnt++;
            }
            ListNode* new_curr = curr ? curr->next : nullptr;
            if (curr != nullptr) curr->next = nullptr;
            ans.push_back(curr_head);
            curr = new_curr;
        }   
        return ans;
    }
};