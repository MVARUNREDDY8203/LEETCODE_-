class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int change[] = {0, 0};
        for (int i=0; i<bills.size(); i++) {
            if (bills[i] == 5) {
                change[0]++;
                continue;
            }
            else if (bills[i] == 10) {
                if (change[0] > 0)  { 
                    change[0]--;
                    change[1]++;
                    continue;
                }
                return false;
            }
            else {
                if (change[1] > 0) {
                    if (change[0] > 0) {
                        change[0]--;
                        change[1]--;
                        continue;
                    }
                    return false;

                }
                else if (change[0] >= 3) {
                    change[0] -= 3;
                    continue;
                }
                
                return false;
            }
        }
        return true;
    }
};