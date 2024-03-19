class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = 0;
        while (l < r) {
            area = max (area, (r-l)*min(height[l], height[r]));
            height[l] < height[r] ? l++ : r--;
        }
        return area;
    }
};







// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         // int maxVol=-1;
//         // int n=height.size();
//         // for(int i=0; i<=n-1; i++){
//         //     for(int j=i+1; j<=n-1; j++){
//         //         int vol=(j-i)*min(height[i],height[j]);
//         //         maxVol=max(vol,maxVol);
//         //     }
//         // }
//         // return maxVol;
//         int maxVol=-1;
//         int l=0;
//         int r=height.size()-1;
        
//         while(r>l){
//             int vol=0;
//             int h=min(height[l],height[r]);
//             vol=(r-l)*h;
//             maxVol=max(vol,maxVol);
//             if(height[l]<height[r]){
//                 l++;
//             }else{
//                 r--;
//             }
//         }
//         return maxVol;

//     }
// };