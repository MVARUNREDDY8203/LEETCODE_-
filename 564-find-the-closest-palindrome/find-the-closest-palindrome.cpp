class Solution {
public:
    long make_palindrome(long first_half, bool even_digits) {
        string res = "";
        if (even_digits) {
            string l = to_string(first_half);
            string rev = l;
            reverse(rev.begin(), rev.end());
            res = l + rev;
            return stol(res);
        }
        string l = to_string(first_half);
        string rev = l.substr(0, l.size() - 1);
        reverse(rev.begin(), rev.end());
        res = l + rev;
        return stol(res);
    }
    string nearestPalindromic(string s) {
        int n = s.size();
        int first_half_size = n % 2 ? n/2 : n/2 - 1;
        long first_half_num = stol(s.substr(0, first_half_size + 1));

        vector<long> possibilites;
        possibilites.push_back(make_palindrome(first_half_num, n % 2 == 0));
        possibilites.push_back(make_palindrome(first_half_num + 1, n % 2 == 0));
        possibilites.push_back(make_palindrome(first_half_num - 1, n % 2 == 0));
        possibilites.push_back((long)pow(10, n - 1) - 1);
        possibilites.push_back((long)pow(10, n) + 1);

        long diff = LONG_MAX, res = 0, org_num = stol(s);
        for (auto candidate: possibilites) {
            cout<<candidate<<" ";
            if (candidate == org_num) continue;
            if (abs(candidate - org_num) < diff) {
                diff = abs(candidate - org_num);
                res = candidate;
            } else if (abs(candidate - org_num) == diff) {
                res = min(res, candidate);
            }
        }
        
        return to_string(res);
    }
};