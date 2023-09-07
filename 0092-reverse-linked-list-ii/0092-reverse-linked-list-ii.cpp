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
    int list_length(ListNode* head){
        if(head == NULL) return 0;
        return 1 + list_length(head->next);
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(left == right) return head;
        int n = list_length(head);
        unordered_map<int, ListNode*> ump;
        ump[0] = NULL;
        ListNode* curr = head;
        int i = 1;
        while(curr != NULL){
            ump[i++] = curr;
            curr = curr->next;
        }
        int rp = right;
        while(rp != left){
            ump[rp]->next = ump[rp-1];
            rp--;
        }

        if(left != 1){
            ump[left-1]->next = ump[right];
            if(right == n) ump[left]->next = NULL;
            else ump[left]->next = ump[right+1];
        }else{
            if(right == n) ump[left]->next = NULL;
            else ump[left]->next = ump[right+1];
            return ump[right];
        }
        return head;
    }

};