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
    ListNode* reverseSegment(ListNode* head, int k) {
        ListNode* end = head;
        int k_copy = k;
        while (end && k_copy) {
            end = end->next;
            k_copy--;
        }
        if (k_copy) return head; // no need to reverse
        ListNode* dummy = new ListNode(0, end);

        ListNode* curr = head;
        k_copy = k;
        while (k_copy) {
            k_copy--;
            ListNode* dummy_next = dummy->next;
            dummy->next = curr;
            curr = curr->next;
            dummy->next->next = dummy_next;
        }
        curr = dummy->next;
        while (curr) {
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
        return dummy->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hol = new ListNode(0, head);
        ListNode* curr = hol;
        int i = 0;
        while (curr) {
            if (i%k == 0) {
                curr->next = reverseSegment(curr->next, k);
                if (hol->next == nullptr) hol->next = curr->next;
            }
            i++;
            curr = curr->next;
        }
        return hol->next;
    }
};