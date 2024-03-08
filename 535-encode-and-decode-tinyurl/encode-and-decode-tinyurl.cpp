class Solution {
    unordered_map<string, int> fmp;
    unordered_map<int, string> rmp;
    string base = "https://turl.com/";
public:
    // Encodes a URL to a shortened URL.
    string encode(string lurl) {
        if (!fmp.count(lurl)) {
            fmp[lurl] = fmp.size() + 1;
            rmp[fmp[lurl]] = lurl; 
        }
        return to_string(fmp[lurl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string surl) {
        return rmp[stoi(surl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));