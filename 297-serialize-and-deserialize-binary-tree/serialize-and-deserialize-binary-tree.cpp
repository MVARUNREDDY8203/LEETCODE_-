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
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        vector<string> tokens;
        while (getline(ss, item, ',')) {
            tokens.push_back(item);
        }

        if (tokens[0] == "null") return nullptr;

        int val = stoi(tokens[0]);
        TreeNode* curr = new TreeNode(val);
        TreeNode* root_starter = new TreeNode(0, curr, nullptr);

        queue<TreeNode*> que;
        que.push(curr);
        int i=1, n = tokens.size();
        for (auto i: tokens) cout<<i<<endl;
        while (!que.empty()) {
            curr = que.front();
            if (curr) cout<<curr->val<<" ";
            que.pop();

            if (i < n) {
                if (!(tokens[i] == "null")) curr->left = new TreeNode(stoi(tokens[i]));
                i++;
                if (!(tokens[i] == "null")) curr->right = new TreeNode(stoi(tokens[i]));
                i++;
            }

            if (curr->left) que.push(curr->left);
            if (curr->right) que.push(curr->right);
        }

        return root_starter->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));