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
    map<pair<TreeNode*, bool>, int> mp;
    int util(TreeNode* root, bool parent_taken) {
        if (!root) return 0;
        if (parent_taken) return util(root->left, false) + util(root->right, false);
        
        if (mp.count({root, parent_taken}) ) return mp[{root, parent_taken}];

        int taken = root->val + util(root->left, true) + util(root->right, true);
        int not_taken = util(root->left, false) + util(root->right, false);

        return mp[{root, parent_taken}] = max(taken, not_taken);
    }
    int rob(TreeNode* root) {
        return util(root, false);
    }
};