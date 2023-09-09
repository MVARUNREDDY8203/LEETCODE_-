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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            n++;
        }
        k = k%n;
        if (k == 0) return head;
        curr = head;
        while (n != k+1) {
            curr = curr->next;
            n--;
        }
        ListNode* nh = curr->next;
        curr->next = NULL;
        curr = nh;
        while (k != 1) {
            curr = curr->next;
            k--;
        }
        curr->next = head;
        return nh;
    }
};