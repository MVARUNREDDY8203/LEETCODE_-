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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 2000) continue;

            int sum = 0;
            for (int j=i; j<nums.size(); j++) {

                sum += nums[j];
                if (sum == 0) {
                    for (int k=i; k<=j; k++) {
                        nums[k] = 2000;
                    }
                    i = j;
                }
            }
        }
        
        ListNode* head2 = new ListNode(2000);
        curr = head2;
        int m = 0;
        while (m < nums.size()) {
            if (nums[m] == 2000) {
                m++;
                continue;
            }
            curr->next = new ListNode(nums[m++]);
            curr = curr->next;
        }
        return head2->next;
    }
};