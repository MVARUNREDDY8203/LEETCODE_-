class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

    int billion_int = 1e9;
    int million_int = 1e6;
    int thousand_int = 1e3;
    string util(int n) {
        string ans = "";
        if (n >= billion_int) {
            ans += util(n/billion_int) + " Billion";
            n = n % billion_int;
        }
        if (n >= million_int) {
            ans += util(n/million_int) + " Million";
            n = n % million_int;
        }
        if (n >= thousand_int) {
            ans += util(n/thousand_int) + " Thousand";
            n = n % thousand_int;
        }
        if (n >= 100) {
            ans += util(n/100) + " Hundred";
            n = n % 100;
        }
        if (n >= 20) {
            ans += " " + tens[n/10];
            n = n % 10;
        }
        if (n > 0) ans += " " + ones[n];
        return ans;
    }
    string numberToWords(int n) {
        if (n == 0) return "Zero";
        return util(n).substr(1);
    }
};