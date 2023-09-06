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
    int length(ListNode* head){
        if(head == NULL) return 0;
        return 1 + length(head->next);
    }
    ListNode* splitter(ListNode* head, int rem){
        if(head == NULL) return NULL;
        if(rem == 1){
            ListNode* temp = head->next;
            head->next = NULL;
            return temp;
        }
        return splitter(head->next, --rem);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = length(head);
        vector<ListNode*> vec(k, NULL);

        ListNode* curr = head;
        int index = 0;

        if(n/k < 1){
            while(curr != NULL){
                vec[index++] = curr;
                curr = splitter(curr, 1);
            }
            return vec;
        }

        int mod = n%k;
        while(curr != NULL){
            vec[index++] = curr;
            if(mod > 0){
                mod--;
                curr = splitter(curr, n/k+1);
            }
            else{
                curr = splitter(curr, n/k);
            }
        }
        return vec;
    }
};