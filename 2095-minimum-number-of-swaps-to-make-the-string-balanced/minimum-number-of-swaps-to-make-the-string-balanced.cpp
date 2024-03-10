class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        for (auto i: s) {
            if (i == '[') size++;
            else if (size !=0) size--;
        }
        return (size+1)/2;
    }
};