class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int diff = 0;
        int one = -1, two = -1;

        for (int i=0; i<s.size(); i++) {
            if (s[i] != goal[i]) {
                diff++;
                one == -1 ? one = i: two = i;
            }

        }

        if (diff == 0) {
            unordered_set<int> uset;
            for (auto i: s) {
                if (uset.find(i) != uset.end()) return true;
                uset.insert(i);
            }            
            return false;
        }
        if (diff == 2) {
            return (s[one] == goal[two] && s[two] == goal[one]);
        }
        return false;
    }
};