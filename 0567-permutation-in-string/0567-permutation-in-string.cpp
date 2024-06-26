class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), m = s1.size();
        vector<int> freq_map(26, 0);
        int l=-1, r = 0, cnt = 0;
        for (int i=0; i<m; i++) freq_map[s1[i] - 'a']++;
        while (r<n) {
            freq_map[s2[r] - 'a']--;
            cnt++;
            while (freq_map[s2[r] - 'a'] < 0) {
                freq_map[s2[++l] - 'a']++;
                cnt--;
            }
            if (cnt == m) {cout<<l<<" "<<r<<endl;return true; }  
            r++;     
        }
        return false;
    }
};