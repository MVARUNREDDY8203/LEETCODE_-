class Solution {
public:
    vector<vector<string>> ans;
    vector<string> bs(int k, int l, int r, vector<string>& products, string &searchWord) {
        int mid = (l+r)/2;
        string& mid_prod = products[mid];
        if (l < r) {
            for (int j=0; j<=k; j++) {
                if (mid_prod[j] < searchWord[j]) return bs(k, l+1, r, products, searchWord);
                if (mid_prod[j] > searchWord[j]) return bs(k, l, mid, products, searchWord);
            }
            return bs(k, l, mid, products, searchWord);
        }
        vector<string> smol_ans;
        for (int i=l; i<l+3 && i < products.size(); i++) {
            string temp = products[i].substr(0, k+1);
            string search_term = searchWord.substr(0, k+1);
            if (temp == search_term) smol_ans.push_back(products[i]);
            else break;
        }
        return smol_ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for (int i=0; i<searchWord.size(); i++) {
            ans.push_back(bs(i, 0, products.size(), products, searchWord));
        } 
        return ans;
    }
};