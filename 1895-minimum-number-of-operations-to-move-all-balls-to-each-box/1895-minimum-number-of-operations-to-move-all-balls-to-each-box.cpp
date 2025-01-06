class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int candidates = 0;
        prefix[0] = 0;
        if (boxes[0] == '1') candidates++;
        for (int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + candidates;
            if (boxes[i] == '1') candidates++;
        }
        suffix[n-1] = 0;
        candidates = 0;
        if (boxes[n-1] == '1') candidates = 1;
        for (int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + candidates;
            if (boxes[i] == '1') candidates++;
        }
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) ans[i] = prefix[i] + suffix[i];
        return ans;
    }
};