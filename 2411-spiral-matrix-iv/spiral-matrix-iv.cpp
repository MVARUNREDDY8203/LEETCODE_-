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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i=0, j=0, curr_direction = 0, movement[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
        while (head != nullptr) {
            ans[i][j] = head->val;

            int newi = i + movement[curr_direction][0];
            int newj = j + movement[curr_direction][1];

            if (min(newi, newj) < 0 || newi >= m || newj >= n || ans[newi][newj] != -1) {
                curr_direction = (curr_direction + 1) % 4;
            }
            i += movement[curr_direction][0];
            j += movement[curr_direction][1];

            head = head->next;
        }
        return ans;
    }
};