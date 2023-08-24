class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        // stripping trailing white spaces

        for(int i=0; i<s.size() && s[i] == ' '; i++){

        }
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(temp != ""){
                    st.push(temp);
                }
                temp = "";
            }
            else{
                temp+=s[i];
            }
        }
        st.push(temp);
        string ans = "";
        while(!st.empty()){
            if(st.top() == ""){
                st.pop();
                continue;
            }
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        return ans.substr(0, ans.size()-1);
    }
};