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
    int total_nodes(ListNode* head){
        return head ? 1 + total_nodes(head->next) : 0;
    }
    ListNode* mN_util(ListNode* head, int rem){
        return (rem > 0) ? mN_util(head->next , rem-1) : head; 
    }
    ListNode* middleNode(ListNode* head) {
        int tn = total_nodes(head);
        return mN_util(head, tn/2);
    }
};