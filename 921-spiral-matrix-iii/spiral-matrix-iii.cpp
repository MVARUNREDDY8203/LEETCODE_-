class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        int m = 0, n = 0;
        vector<vector<int>> spm(m, vector<int>(n, 0));
        vector<vector<int>> ans;
        int cnt = rows*cols;
        int i = rs, j = cs;
        int dir[4] = {1, 0, 0, 0}; // left right up down
        int boundary[4] = {cs+1, rs+1, cs-1, rs-1};

        while (cnt > 0) {
            if (i >=0 && i < rows && j >= 0 && j < cols) {
                cnt--;
                ans.push_back({i, j});
            }

            if (dir[0] && j <= boundary[0]) {
                // east
                if (j == boundary[0]) {
                    dir[0] = 0;
                    boundary[0]++;
                    dir[1] = 1;
                    i++;
                }
                else j++;

            }else if (dir[1] && i <= boundary[1]) {
                // south
                if (i == boundary[1]) {
                    dir[1] = 0;
                    dir[2] = 1;
                    boundary[1]++;
                    j--;
                }
                else i++;

            }else if (dir[2] && j >= boundary[2]) {
                if (j == boundary[2]) {
                    dir[2] = 0;
                    dir[3] = 1;
                    boundary[2]--;
                    i--;
                }
                else j--;

            }else {
                if (i == boundary[3]) {
                    dir[3] = 0;
                    dir[0] = 1;
                    boundary[3]--;
                    j++;
                }
                else i--;

            }
        }

        return ans;
    }
};