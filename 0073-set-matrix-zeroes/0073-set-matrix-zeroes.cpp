class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        int isroot = nums[0][0];
        int colz = 0, rowz = 0;
        for (int i=0; i<m; i++) if (nums[i][0] == 0) {
            colz++;
            break;
        }
        for (int j=0; j<n; j++) if (nums[0][j] == 0) {
            rowz++;
            break;
        } 
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (nums[i][j] == 0) {
                    nums[i][0] = 0;
                    nums[0][j] = 0;
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
        for (int j=n-1; j>0; j--) {
            if (nums[0][j] == 0)  {
                for (int i=0; i<m; i++) {
                    nums[i][j] = 0;
                }
            }
        }
        for (int i=m-1; i>0; i--) {
            if (nums[i][0] == 0) {
                for (int j=0; j<n; j++) {
                    nums[i][j] = 0;
                }
            }
        }
        if (colz) for (int i=0; i<m; i++) nums[i][0] = 0;
        if (rowz) for (int j=0; j<n; j++) nums[0][j] = 0;
    }
};