class Solution {
public:
    // int gcd(int a, int b) {
    //     int result = min(a,b);
    //     while (result > 0) {
    //         if (a % result == 0 && b % result == 0) return result;
    //         result--;
    //     }
    //     return 1;
    // }
    string fractionAddition(string expr) {
        if (expr[0] != '+' && expr[0] != '-') expr = "+" + expr;
        int n = expr.size();

        // denominator
        string denom = "";
        vector<int> denoms;
        for (int i=0; i<n; i++) {
            if (expr[i] == '+' || expr[i] == '-') {
                if (denom.size() < 1) continue;
                denoms.push_back(stoi(denom));
                denom = "";
                continue;
            }
            if (expr[i] == '/') {
                denom = "";
                continue;
            }
            denom += expr[i];
        }
        if(denom.size() >= 1) denoms.push_back(stoi(denom));
        //numerator
        string nume = "";
        vector<int> numes;
        for (int i=0; i<n; i++) {
            if (expr[i] == '+' || expr[i] == '-') {
                nume = "";
                continue;
            }
            if (expr[i] == '/') {
                if (nume.size() < 1) continue;
                numes.push_back(stoi(nume));
                nume = "";
                continue;
            }
            nume += expr[i];
        }
        // // if (nume.size() >= 1) numes.push_back(stoi(nume));
        // for (auto i: numes) cout<<i<<" ";
        // cout<<endl;

        vector<char> signs;
        for (int i=0; i<n; i++) if (expr[i] == '+' || expr[i] == '-') signs.push_back(expr[i]);
        nume = 1, denom = 1;

        int denom_int = denoms[0], nume_int = numes[0], prev_denom = 1;
        cout<<signs[0]<<endl;
        if (signs[0] == '-') nume_int *= -1;
        cout<<nume_int<<"/"<<denom_int<<endl;

        for (int i=1; i<numes.size(); i++) {
            int sign = signs[i] == '+' ? 1 : -1;
            prev_denom = denom_int;
            denom_int *= denoms[i];
            nume_int = nume_int * (denom_int/prev_denom) + sign * numes[i] * (denom_int/denoms[i]);
            cout<<nume_int<<"/"<<denom_int<<endl;
        }

        int hcf = __gcd(abs(nume_int), abs(denom_int));
        nume_int = nume_int / hcf;
        denom_int = denom_int / hcf;
        return to_string(nume_int) + '/' + to_string(denom_int);
    }
};