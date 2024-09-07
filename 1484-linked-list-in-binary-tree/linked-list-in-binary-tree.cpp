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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:    
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> que;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
            if (!root) return;
            if (root->val == head->val) {
                que.push(root);
            }
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        function<bool(TreeNode*, ListNode*)> util = [&](TreeNode* root, ListNode* head) -> bool {
            if (head == NULL) return true;
            if (root == NULL) return false;
            if (root->val != head->val) return false;

            return util(root->left, head->next) || util(root->right, head->next);
        };
        while (!que.empty()) {
            if (util(que.front(), head)) return true;
            que.pop();
        }
        return false;
    }
};