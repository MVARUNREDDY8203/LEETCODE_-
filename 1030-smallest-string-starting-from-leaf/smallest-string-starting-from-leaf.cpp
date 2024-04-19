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
    vector<string> dict;
    void dfs(TreeNode* root, string curr) {
        if (!root) return;

        string pass = curr;
        pass += root->val + 'a';
        
        if (!root->left && !root->right) {
            reverse(pass.begin(), pass.end());
            dict.push_back(pass);
            return;
        }

        dfs(root->left, pass);
        dfs(root->right, pass);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        if (dict.size() == 0) return "";
        sort(dict.begin(), dict.end());
        return dict[0];
    }
};