class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        sort(products.begin(), products.end());
        auto it = products.begin();
        string curr = "";
        vector<string> temp;
        for (int i=0; i<searchWord.size(); i++) {
            temp.clear();
            curr += searchWord[i];
            it = lower_bound(products.begin(), products.end(), curr);
            for (int j=0; j<3 && it+j != products.end(); j++) {
                string s = *(it+j);
                if (s.find(curr)) break;    // return first idx of curr in s, if not returns n_pos so ...
                temp.push_back(s);
            }
            ans.push_back(temp);
        } 
        return ans;
    }
};