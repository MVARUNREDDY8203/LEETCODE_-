class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size(), n2 = nums2.size();

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) ans.emplace_back(nums1[i++]);
            else ans.emplace_back(nums2[j++]);
        }
        while (i < n1) ans.emplace_back(nums1[i++]);
        while (j < n2) ans.emplace_back(nums2[j++]);

        int k = (n1+n2)/2;
        if ((n1 + n2) % 2 == 0) return (double)(ans[k] + ans[k-1]) / 2;
        return (double)ans[k];
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int idx1 = 0, idx2 = 0, n1 = nums1.size(), n2 = nums2.size(), total = 0;
//         int k = (n1 + n2) / 2;
//         bool twoans = (n1 + n2) % 2 == 0;
//         vector<int> &A = n1 <= n2 ? nums1 : nums2;
//         vector<int> &B = n1 <= n2 ? nums2 : nums1;
//         n1 = A.size();
//         n2 = B.size();
//         // cout<<A.size()
//         if (n1 == 0) {
//             if (n2 == 0) return 0;
//             if (n2 % 2 == 0) return (double)(B[k] + B[k-1]) / 2;
//             return B[k];
//         }

//         while (total < k) {
//             if (idx1 >= n1) {
//                 if (!twoans) {
//                     return (double)B[(k - n1) -1];
//                 }else {
//                     if (n1 == n2) return (double)(A[n1-1] + B[0]) / 2;
//                     return (double)(B[(k - n1) -1] + B[(k - n1)]) / 2;
//                 }
//             }
//             if (A[idx1] <= B[idx2]) idx1++;
//             else idx2++; 
//             total++;
//         }
//         if (idx1 >= n1) {
//             if (!twoans) {
//                 return (double)B[(k - n1) -1];
//             }else {
//                 if (n1 == n2) return (double)(A[n1-1] + B[0]) / 2;
//                 cout<<"here";
//                 return (double)(B[(k - n1) -1] + B[(k - n1)]) / 2;
//             }
//         }
//         if (twoans) return ((double)(A[--idx1] + B[--idx2]) / 2);
//         return (double)(min(A[idx1], B[idx2]));
//     }
// };
// // class Solution {
// // public:
// //     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// //         int n1 = nums1.size(), n2 = nums2.size();
// //         int l1 = 0, r1 = n1-1, l2 = 0, r2 = n2-1, k = -1;
// //         vector<int> &A = n1 <= n2 ? nums1 : nums2;
// //         vector<int> &B = n1 <= n2 ? nums2 : nums1;
// //         bool twoans = (n1 + n2) % 2 == 0;

// //         while (l1 <= r1 && l2 <= r2) {
// //             int mid1 = (l1 + r1) / 2;
// //             int mid2 = (l2 + r2) / 2;
            
// //             if (A[mid] <= B[mid + 1]) {
// //                 if (B[mid] <= A[mid+1]) {
// //                     // here is the solution
// //                     if (!twoans) return max(A[mid], B[mid]);
// //                     else return (max(A[mid], B[mid]) + min(A[mid+1], B[mid+1])) / 2;
// //                 }
// //                 else {
// //                     l1 = mid1 + 1;
// //                     if (l1 > r1) {
// //                         // here is another solution n2 - k th element

// //                     }
// //                     int prev_mid1 = mid1;
// //                     mid1 = (l1 + r1) / 2;
// //                     r2 -= abs(prev_mid1 - mid1);
// //                 }
// //             }
// //             else {
// //                 int prev_mid1 = mid1;
// //                 r1 = mid1 - 1;
// //                 if (r1 < l1) {
// //                     here is another solution n2 - k th element
// //                 }
// //                 mid1 = (l1 + r1) / 2;
// //                 l2 += abs(prev_mid1 - mid1);
// //             }
// //         }
// //         if (l1 > r1 || r1 < l1) {

// //         }
// //     }
// // };