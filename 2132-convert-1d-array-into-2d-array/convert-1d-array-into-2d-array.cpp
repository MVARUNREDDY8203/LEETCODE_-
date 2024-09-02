class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i =0;
        for (i=0; i<org.size(); i++) {
            temp.push_back(org[i]);
            if (temp.size() == n) {
                ans.push_back(temp);
                temp.clear();
            }
        }
        if (temp.size() != 0) return {};
        if (ans.size() != m) return {};
        return ans;
    }
};