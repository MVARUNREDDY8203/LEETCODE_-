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
    int gcd(int a, int b) {
        int c = min(a, b);
        while (c > 0) {
            if (a % c == 0 && b % c == 0) return c;
            c--;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            curr->next = new ListNode(gcd(curr->val, curr->next->val), curr->next);
            curr = curr->next->next;
        }
        return head;
    }
};