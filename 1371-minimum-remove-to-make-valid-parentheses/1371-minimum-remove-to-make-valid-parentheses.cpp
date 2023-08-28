class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size = s.size();
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i] = '0';
                }
            }
        }
        if(!st.empty()){
            for(int i=s.size(); i>=0 && !st.empty(); i--){
                if(s[i] == '('){
                    st.pop();
                    s[i] = '0';
                }
            }
        }  
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != '0'){
                ans += s[i];
            }
        }
        return ans;
    }
};