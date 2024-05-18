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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(INT_MIN);
        ListNode* even = new ListNode(INT_MIN);
        ListNode* oddptr = odd;
        ListNode* evenptr = even;

        ListNode* curr = head;
        int idx = 1;
        while (curr) {
            if (idx % 2 == 1) {
                oddptr->next = curr;
                oddptr = oddptr->next;
            }
            else {
                evenptr->next = curr;
                evenptr = evenptr->next;
            }
            curr = curr->next;
            idx++;
        }
        evenptr->next = NULL;
        oddptr->next = even->next;
        return odd->next;
    }
};