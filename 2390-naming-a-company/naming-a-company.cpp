class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> dict(26);

        for (auto i: ideas) {
            dict[i[0] - 'a'].insert(i.substr(1));
        }
        long long ans = 0;
        for (int i='a'; i<='z'; i++) {
            for (int j=i+1; j<='z'; j++) {
                int sum = 0;
                for (auto &it : dict[i - 'a']) {
                    sum += dict[j - 'a'].count(it);
                }
                ans += 2 * ( dict[i-'a'].size() - sum ) * (dict[j - 'a'].size() - sum);
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
//         long long ans = 0;
//         unordered_set<string> dict;
//         for (auto i: ideas) dict.insert(i);

//         for (int i=0; i<ideas.size(); i++) {
//             for (int j=i+1; j<ideas.size(); j++) {
//                 swap(ideas[i][0], ideas[j][0]);
//                 if (!dict.count(ideas[i]) && !dict.count(ideas[j])) ans += 2;
//                 swap(ideas[i][0], ideas[j][0]);
//             }
//         }

//         return ans;
//     }
// };