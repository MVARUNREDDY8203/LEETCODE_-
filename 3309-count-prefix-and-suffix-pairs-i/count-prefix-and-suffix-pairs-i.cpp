class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i=0; i<words.size()-1; i++) {
            for (int j=i+1; j<words.size(); j++) {
                string p = words[i];
                string q = words[j];
                // if (i == 0 && j == 2) cout<<"yes";

                bool check = 0;
                int k = 0;
                while (k < p.size()) {
                    if (p[k] == q[k]) k++;
                    else break;
                }
                if (k != p.size()) continue;
                k = p.size() - 1;
                int l = q.size() - 1;
                while (k >= 0) {
                    if (p[k] == q[l]) {
                        k--;
                        l--;
                    }
                    else break;
                }
                if (k < 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};