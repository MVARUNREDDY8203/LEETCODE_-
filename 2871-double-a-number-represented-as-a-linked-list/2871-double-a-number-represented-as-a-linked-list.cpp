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
    int double_val(ListNode* head){
        if(head == NULL) return 0;
        int carry = double_val(head->next);
        head->val *= 2;
        head->val += carry;

        carry = head->val / 10;
        head->val %= 10;
        return carry;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = double_val(head);
        if(carry == 1){
            ListNode* new_head = new ListNode(carry, head);
            return new_head;
        }
        return head;
    }
};