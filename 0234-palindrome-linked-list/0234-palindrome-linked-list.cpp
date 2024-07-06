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
    ListNode* reverse_ll(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* dummy_next = dummy->next;

        ListNode* curr = head;
        while (curr) {
            dummy_next = dummy->next;
            dummy->next = curr;
            curr = curr->next;
            dummy->next->next = dummy_next;
        }

        head->next = nullptr;
        return dummy->next;
    }
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            cnt++;
        }
        int half = cnt/2;  
        ListNode* head2 = head;

        ListNode* head1 = head;
        while (half) {
            half--;
            head2 = head2->next;
        }
        if (cnt % 2 == 1) head2 = head2->next;
        head2 = reverse_ll(head2);

        while (head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};