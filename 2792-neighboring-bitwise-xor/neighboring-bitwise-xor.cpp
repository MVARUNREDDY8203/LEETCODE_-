class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool a1 = 0;
        for (auto i: derived) if (i == 1) a1 = !a1;
        return a1 == 0;
    }
};