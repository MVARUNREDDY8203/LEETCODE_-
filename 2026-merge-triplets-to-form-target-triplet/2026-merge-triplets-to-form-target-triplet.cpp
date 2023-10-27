class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int one = target[0], two = target[1], three = target[2], n = triplets.size();
        unordered_map<int, int>;
        bool possible1 = false, possible2 = false, possible3 = false;
        for (int i=0; i<n; i++) {
            if (triplets[i][0] == one && triplets[i][1] <= two && triplets[i][2] <= three) {
                possible1 = true;
                break;
            }
        }
        if (!possible1) return false;
        for (int i=0; i<n; i++) {
            if (triplets[i][0] <= one && triplets[i][1] == two && triplets[i][2] <= three) {
                possible2 = true;
                break;
            }
        }
        if (!possible2) return false;
        for (int i=0; i<n; i++) {
            if (triplets[i][0] <= one && triplets[i][1] <= two && triplets[i][2] == three) {
                possible3 = true;
                break;
            }
        }
        return possible3;
    }
};