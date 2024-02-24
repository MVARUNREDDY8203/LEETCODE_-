class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<int, int> count1;
        for (auto i: s1) count1[i]++;

        unordered_map<int, int> curr_count = count1;
        // sliding window starter
        for (int i=0; i < s1.size(); i++) {
            curr_count[s2[i]]--;
            if (curr_count[s2[i]] == 0) curr_count.erase(s2[i]);
        }
        if (curr_count.size() == 0) return true;

        // sliding window propogation
        for (int j = s1.size(); j<s2.size(); j++) {
            curr_count[s2[j-s1.size()]]++;
            if (curr_count[s2[j-s1.size()]] == 0) curr_count.erase(s2[j-s1.size()]);

            curr_count[s2[j]]--;
            // if (curr_count.count(s2[j])) curr_count[s2[j]]--;

            if (curr_count[s2[j]] == 0) curr_count.erase(s2[j]);
            if (curr_count.size() == 0) return true;
            cout<<j<<" "<<curr_count.size()<<endl;
        }
        return false;
    }
};


// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         if (s1.size() > s2.size()) return false;

//         unordered_map<int, int> count1;
//         for (auto i: s1) count1[i]++;
//         for (int start=0; start<s2.size(); start++) {
//             if (count1.count(s2[start])) {
//                 unordered_map<int, int> curr_count = count1;
//                 for (int end = start; end<s2.size(); end++) {
//                     if (curr_count.count(s2[end])) curr_count[s2[end]]--;
//                     else {
//                         break;
//                     }

//                     if (curr_count[s2[end]] == 0) curr_count.erase(s2[end]);
//                     if (curr_count.size() == 0) return true;
//                 }
//             }
//         }

//         return false;
//     }
// };