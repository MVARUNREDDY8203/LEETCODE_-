class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int s1 = 0, s2 = 0, n2 = num2, n1 = num1;
        while (n2) {
            s2 += n2 % 2;
            n2 /= 2;
        }
        int bits[32];
        memset(bits, 0, sizeof(bits));
        int idx = 31;
        while (n1) {
            cout<<n1<<endl;
            if (n1 % 2) {
                cout<<"yea"<<endl;
                bits[idx] = 1;
                s1++;
            }
            idx--;
            n1 /= 2;
        }
        for (int i=0; i<32; i++) cout<<bits[i]<<" ";
        cout<<endl;
        cout<<s1<<" "<<s2<<endl;

        if (s2 < s1) {
            for (int i=0; i<32; i++) {
                if (bits[i] == 1) {
                    if (s2 > 0) s2--;
                    else bits[i] = 0;
                }
            }
        }
        else if (s2 > s1) {
            s2 -= s1;
            for (int i=31; i>=0; i--) {
                if (bits[i] == 0 && s2 > 0) {
                    bits[i] = 1;
                    s2--;
                }
            }
        }
        for (int i=0; i<32; i++) cout<<bits[i]<<" ";
        cout<<endl;
        int ans = bits[0];
        for (int i=1; i<32; i++) {
            ans *= 2;
            ans += bits[i];
        }
        return ans;
    }
};