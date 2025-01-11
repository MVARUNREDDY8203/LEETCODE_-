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
    vector<int> ans;
    void util (TreeNode* root, int lvl) {
        if (root == nullptr) return;

        if (lvl > ans.size()) ans.push_back(INT_MIN);

        ans[lvl - 1] = max(ans[lvl - 1], root->val);

        if (lvl == 2) cout<<ans[lvl-1]<<" "<<root->val<<" ";

        util(root->left, lvl + 1);
        util(root->right, lvl + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        util(root, 1);
        return ans;
    }
};