class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 1, bit_xor<int>());
    }
};