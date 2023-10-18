class Solution {
public:
    char binarySearchSmn(vector<char> &letters, char target, int l, int r) {
        if (l > r) return letters[0];
        if (r - l <= 1) {
            if (letters[l] > target) return letters[l];
            if (letters[r] > target) return letters[r];
            return letters[0];
        }
        int mid = (l+r)/2;
        if (letters[mid] <= target) return binarySearchSmn(letters, target, mid+1, r);
        return binarySearchSmn(letters, target, l, mid);
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        return binarySearchSmn(letters, target, 0, letters.size()-1);
    }
};