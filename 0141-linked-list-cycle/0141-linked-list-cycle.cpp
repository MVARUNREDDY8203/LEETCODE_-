/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //TORTOISE AND HARE ALGO
    bool hasCycle(ListNode* head){
        if(head == NULL || head->next == NULL) return false;

        ListNode* slowPtr = head->next;
        ListNode* fastPtr = head->next->next;

        while(fastPtr != NULL && fastPtr->next != NULL && fastPtr->next->next != NULL){
            if(slowPtr == fastPtr) return true;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return false;
    }
    // bool hasCycle(ListNode *head) {
    //     unordered_map<ListNode*, bool> mp;
    //     while(head != NULL && head->next != NULL){
    //         if(mp[head]) return true;
    //         else mp[head] = true;
    //         head=head->next;
    //     }
    //     return false;
    // }

    // CONSTRAINT EXPOITATION METHOD
    // bool Util(ListNode* head, int pos){
    //     if(head == NULL) return false;
    //     if(pos>=10000) return true;
    //     if(head->next == NULL) return false;
    //     return Util(head->next, pos+1);
    // }
    // bool hasCycle(ListNode *head) {
    //     return Util(head,0);
    // }
};