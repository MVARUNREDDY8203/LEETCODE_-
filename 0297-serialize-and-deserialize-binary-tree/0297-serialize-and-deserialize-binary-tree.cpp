/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;

        que.push(root);
        string ser = "";
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            
            if (curr) {
                ser += to_string(curr->val) + ",";

                que.push(curr->left);
                que.push(curr->right);
            }
            else {
                ser += "null,";
            }
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        string curr_val = "";
        int i=0, n = data.size();
        while (i < n && data[i] != ',') curr_val += data[i++];
        i++;
        if (curr_val == "null") return nullptr;

        int val = stoi(curr_val);
        TreeNode* curr = new TreeNode(val);
        TreeNode* root_starter = new TreeNode(0, curr, nullptr);

        queue<TreeNode*> que;
        que.push(curr);
        while (!que.empty()) {
            curr = que.front();
            que.pop();
            if (curr) cout<<curr->val<<endl;

            curr_val = "";
            while (i < n && data[i] != ',')  curr_val += data[i++];
            i++;
            if (!(curr_val == "null") && curr_val.size()) curr->left = new TreeNode(stoi(curr_val));

            curr_val = "";
            while (i < n && data[i] != ',')  curr_val += data[i++];
            i++;
            if (!(curr_val == "null") && curr_val.size()) curr->right = new TreeNode(stoi(curr_val));

            if (curr->left) que.push(curr->left); 
            if (curr->right) que.push(curr->right);
        }

        return root_starter->left;
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));