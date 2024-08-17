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
    unordered_map<string, int> ump;
    vector<TreeNode*> ans;
    string serialize(TreeNode* root) {
        if (!root) return "#";

        string curr_subtree = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);

        if (ump.count(curr_subtree)) {
            cout<<curr_subtree<<endl;
            if (ump[curr_subtree] < 2) ans.push_back(root);
        }
        ump[curr_subtree]++;

        return curr_subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string dummy = serialize(root);
        return ans;
    }
};