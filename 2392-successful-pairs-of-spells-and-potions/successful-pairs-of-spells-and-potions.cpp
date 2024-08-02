class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        // int l = 
        vector<int> pairs;
        for (int i=0; i<spells.size(); i++) {
            int l = 0, r = potions.size()-1;

            while (l < r) {
                int mid = l + (r - l) / 2;
                long long  curr = (long long)potions[mid] * (long long)spells[i];
                if (curr < success) {
                    l = mid + 1;
                }
                else {
                    r = mid;
                }
            }
            pairs.push_back((long long)potions[l] * spells[i] >= success ? potions.size() - l : 0);
        }
        return pairs;
    }
};