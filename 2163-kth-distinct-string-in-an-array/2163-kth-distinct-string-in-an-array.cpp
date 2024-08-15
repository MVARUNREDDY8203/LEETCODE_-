class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> ump;
        for (auto i: arr) ump[i]++;
    
        for (int i=0; i<arr.size(); i++) {
            if (ump[arr[i]] == 1) k--;
            if (k == 0) return arr[i];
        }
        return "";
    }
};