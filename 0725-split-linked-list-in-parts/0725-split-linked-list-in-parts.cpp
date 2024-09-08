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
        
        int npp = n / k;
        int rem = n % k;

        curr = head;
        vector<ListNode*> ans;
        for (int i=0; i<k; i++) {
            int cnt = 1;
            ListNode* curr_head = curr;
            int curr_npp = npp;
            if (rem) {
                curr_npp++;
                rem--;
            }
            while (cnt < curr_npp && curr_head != nullptr) {
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