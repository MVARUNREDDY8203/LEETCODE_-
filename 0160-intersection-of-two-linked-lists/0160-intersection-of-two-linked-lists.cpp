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
    ListNode* util(ListNode* headA, ListNode* headB) {
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0;
        ListNode* currA = headA;
        while (currA) {
            currA = currA->next;
            cntA++;
        }
        int cntB = 0;
        ListNode* currB = headB;
        while (currB) {
            currB = currB->next;
            cntB++;
        }
        currA = headA;
        currB = headB;
        if (cntA > cntB) {
            while (cntA != cntB) {
                currA = currA->next;
                cntA--;
            }
            return util(currA, currB);
        }
        while (cntB != cntA) {
            currB = currB->next;
            cntB--;
        }
        return util(currA, currB);
    }
};