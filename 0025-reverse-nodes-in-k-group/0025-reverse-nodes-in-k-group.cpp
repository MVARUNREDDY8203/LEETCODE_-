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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i=0; i<k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }
        curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        for (int i=0; i<k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
// ListNode* reverseKGroup(ListNode* head, int k) {
//     if (!head->next || k == 1) return head;

//     unordered_map<int, ListNode*> ump;
//     ListNode* curr = head;
//     int index = 1;
//     while (curr) {
//         ump[index++] = curr;
//         curr = curr->next;
//     }

//     int i2 = k;
//     while (i2 <= index) {
//         curr = ump[i2];
//         int i = i2-1;
//         while (i > i2-k) {
//             cout<<curr->val<<" ";
//             curr->next = ump[i--];
//             curr = curr->next;
//             cout<<curr->val<<" ";
//         }
//         i2 += k;
//         if (ump.find(i2) != ump.end()) curr->next = ump[i2];
//         else break;
//     }

//     if (--index % k == 0) {
//         curr->next = NULL;
//     }else{
//         i2 -= k;
//         curr->next = ump[++i2];
//     }

//     return ump[k];
// }