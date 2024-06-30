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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* starter = new ListNode(0);
        ListNode* curr3 = starter;
        int carry = 0;
        while (curr1 && curr2) {
            int sum = carry + (curr1->val + curr2->val);
            carry = sum / 10;
            int place_val = sum % 10;

            curr3->next = new ListNode(place_val);

            curr3 = curr3->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while (curr1) {
            int sum = carry + (curr1->val);
            carry = sum / 10;
            int place_val = sum % 10;
            
            curr3->next = new ListNode(place_val);

            curr3 = curr3->next;
            curr1 = curr1->next;
            // l2 = l2->next;
        }
        while (curr2) {
            int sum = carry + (curr2->val);
            carry = sum / 10;
            int place_val = sum % 10;
            
            curr3->next = new ListNode(place_val);

            curr3 = curr3->next;
            // l1 = l1->next;
            curr2 = curr2->next;
        }
        if (carry) curr3->next = new ListNode(1);

        return starter->next;
    }
};