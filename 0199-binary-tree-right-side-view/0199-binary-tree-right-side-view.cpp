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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> lvls;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        while (!que.empty()) {
            TreeNode* curr = que.front().first;
            int lvl = que.front().second;
            que.pop();

            if (curr == nullptr) continue;

            // cout<<curr->val<<endl;
            if (lvl+1 > lvls.size()) {
                vector<int> new_lvl;
                new_lvl.push_back(curr->val);
                lvls.push_back(new_lvl);
            } else {
            // cout<<"here"<<endl;
                lvls[lvl].push_back(curr->val);
            }

            que.push({curr->left, lvl+1});
            que.push({curr->right, lvl+1});
        }

        vector<int> ans;
        for (int i=0; i<lvls.size(); i++) {
            int size = lvls[i].size();
            ans.push_back(lvls[i][size-1]);
        }
        return ans;

    }
};