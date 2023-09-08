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
        ListNode* curr = head;
        int size = 0;
        while(curr != NULL){
            curr = curr->next;
            size++;
        }
        int prev = size - n;
        if (prev == 0) return head->next;
        curr = head;
        while (prev != 1) {
            curr = curr->next;
            prev--;
        }

        curr->next = curr->next->next;
        return head;
    }
};

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         unordered_map<int, ListNode*> ump;
//         ListNode* curr = head;
//         int index = 1;
//         while (curr != NULL) {
//             ump[index++] = curr;
//             curr = curr->next;
//         }
//         ump[index] == NULL;
//         int del = index-n;
//         if(del == 1) return head->next;
//         ump[del-1]->next = ump[del+1];
//         return head;
//     }
// };