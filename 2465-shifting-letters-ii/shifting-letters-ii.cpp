class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> shift;
        for (int i=0; i<shifts.size(); i++) {
            shift[shifts[i][0]] += (shifts[i][2] == 1 ? 1 : -1);
            shift[shifts[i][1] + 1] += (shifts[i][2] == 1 ? -1 : 1);
        }
        int net_shift = 0;
        for (int i=0; i<s.size(); i++) {
            net_shift += shift[i];
            s[i] = ((((s[i] - 'a') + net_shift + 26 * 10000) % 26) + 'a');
        }
        
        return s;
    }
};