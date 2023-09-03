class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1 = s1, t2 = s1, t3 = s1;
        swap(t1[0], t1[2]);
        swap(t2[1], t2[3]);
        swap(t3[0], t3[2]);
        swap(t3[1], t3[3]);

        if(s1 == s2 || t1 == s2 || t2 == s2 || t3 == s2) return true;
        return false;
    }
};

// class Solution {
// public:
//     bool canBeEqual(string s1, string s2) {
//         for(int i=0; i<4; i++){
//             if(s1[i] == s2[i]) {
//                 s2[i] = '0';
//                 continue;
//             }
//             if(s1[i] == s2[(i+2)%4]) s2[(i+2)%4] = '0';
//         }
//         cout<<s2<<endl;
//         for(auto i: s2){
//             if(i != '0') return false;
//         }
//         return true;
//     }
// };