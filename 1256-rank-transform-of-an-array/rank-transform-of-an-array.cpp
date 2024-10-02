class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end(), greater<int>());
        unordered_map<int, int> ump;
        int rank = 1;
        for (int i=sorted.size()-1; i>=0; i--) {
            if (!ump.count(sorted[i])) ump[sorted[i]] = rank++;
        }
        for (int i=0; i<arr.size(); i++) {
            arr[i] = ump[arr[i]];
        }
        return arr;
    }
};