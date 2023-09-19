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
    void preorder(TreeNode* root, vector<int> & vals) {
        if (!root) return;
        vals.push_back(root->val);
        preorder(root->left, vals);
        preorder(root->right, vals);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        preorder(root, vals);
        int min_val = INT_MAX;
        for(int i=0; i<vals.size(); i++){
            for(int j=i+1; j<vals.size(); j++){
                min_val = min(min_val, abs(vals[i]-vals[j]));
            }
        }
        return min_val;
    }
};