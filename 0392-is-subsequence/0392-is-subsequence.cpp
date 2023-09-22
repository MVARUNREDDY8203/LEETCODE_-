class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr1 =0, ptr2 = 0;
        if(s.size() == 0) return true;

        while(true){
            if(ptr2 >= s.size()) return true;
            if(ptr1 > t.size()) return false;
            if(t[ptr1] == s[ptr2]){
                ptr2++;
            }
            ptr1++;
        }
        return false;
    }
};