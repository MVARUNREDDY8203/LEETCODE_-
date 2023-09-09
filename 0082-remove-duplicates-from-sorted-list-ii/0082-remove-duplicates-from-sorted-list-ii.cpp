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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(200, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        int curr_val = head->val;
        while (curr) {
            if (curr->next && curr_val == curr->next->val) {
                while (curr && curr->val == curr_val) {
                    curr = curr->next;
                }
                prev->next = curr;
                if(curr) curr_val = curr->val;
                continue;
            }
            curr = curr->next;
            if(curr) curr_val = curr->val;
            prev = prev->next;
        }
        return dummy->next;
    }
};
// ListNode* deleteDuplicates(ListNode* head) {
//     map<int, int> mp; // mp<val, count>
//     map<int, ListNode*> addr; // mp<val, addr>

//     ListNode* curr = head;
//     while (curr) {
//         mp[curr->val]++;
//         addr[curr->val] = curr;
//         curr = curr->next;
//     }

    
//     for (auto i: mp) {
//         if (i.second > 1) {
//             addr.erase(i.first);
//         }
//     }

//     ListNode* dummy = new ListNode(200);
//     curr = dummy;

//     for (auto i: addr) {
//         curr->next = i.second;
//         curr = curr->next;
//     }
//     curr->next = NULL;

//     return dummy->next;
// }