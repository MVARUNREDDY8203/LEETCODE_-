class Solution {
public:
    
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        vector<vector<int>> nums(m*3, vector<int>(m*3, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == '/') {
                    nums[i*3][j*3+2] = 1;
                    nums[i*3+1][j*3+1] = 1;
                    nums[i*3+2][j*3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    nums[i*3][j*3] = 1;
                    nums[i*3+1][j*3+1] = 1;
                    nums[i*3+2][j*3+2] = 1;
                }
            }
        }
        function<void(int, int)> marker = [&](int i, int j) -> void {
            if (i < 0 || j < 0 || i >= 3*m || j >= 3*m) return;

            if (nums[i][j] == 0) {
                nums[i][j] = 1;
                marker(i+1, j);
                marker(i-1, j);
                marker(i, j+1);
                marker(i, j-1);
            }
        };
        int cnt = 0;
        for (int i=0; i<nums.size(); i++)  {
            for (int j=0; j<nums[0].size(); j++) {
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int i=0; i<nums.size(); i++)  {
            for (int j=0; j<nums[0].size(); j++) {
                if (nums[i][j] == 0) {
                    cnt++;
                    marker(i, j);
                }
            }
            // cout<<endl;
        }
        return cnt;
    }
};