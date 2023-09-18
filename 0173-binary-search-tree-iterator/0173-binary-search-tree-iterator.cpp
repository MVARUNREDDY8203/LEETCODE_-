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
class BSTIterator {
public:
    vector<TreeNode*> tree;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        tree.push_back(root);
        inorder(root->right);
    }

    TreeNode* itr = NULL;
    int itx = 0;
    BSTIterator(TreeNode* root) {
        itr = new TreeNode(-1);
        tree.push_back(new TreeNode(-1));
        inorder(root);
        tree.push_back(NULL);   
        itx = 0;     
    }
    
    int next() {
        return tree[++itx]->val;
    }
    
    bool hasNext() {
        return (tree[itx+1] ? true : false);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */