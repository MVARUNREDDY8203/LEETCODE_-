class Solution {
public:
    void top_l(int si, int ei, int sj, int ej, vector<vector<int>> &matrix, vector<int> &ans){
        int i = si;
        int j = sj;
        for(j=sj; j<=ej; j++){
            ans.push_back(matrix[i][j]);
        }
        i = si+1;
        j = ej;
        for(i=si+1; i<=ei; i++){
            ans.push_back(matrix[i][j]);
        }
        if(si+1<=ei && sj<=ej-1){
            bottom_l(si+1, ei, sj, ej-1, matrix, ans);
        }
    }

    void bottom_l(int si, int ei, int sj, int ej, vector<vector<int>> & matrix, vector<int> & ans){
        int i = ei;
        int j = ej;

        for(j = ej; j>=sj; j--){
            ans.push_back(matrix[i][j]);
        }
        i = ei-1;
        j = sj;
        for(i = ei-1; i>=si; i--){
            ans.push_back(matrix[i][j]);
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int si = 0;
        int sj = 0;
        int ei = matrix.size()-1;
        int ej = matrix[0].size()-1;
        vector<int> ans;

        while(si<=ei && sj<=ej){
            top_l(si++, ei--, sj++, ej--, matrix, ans);
        }
        return ans;
    }
};