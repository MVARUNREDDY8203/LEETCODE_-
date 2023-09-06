class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            string op = tokens[i];
            if(op == "+" || op == "-" || op == "*" || op == "/"){
                int curr = st.top();
                st.pop();
                int prev = st.top();
                st.pop();
                
                if(op == "+"){
                    st.push(prev + curr);
                }else if(op == "-"){
                    st.push(prev - curr);
                }else if(op == "/"){
                    st.push(prev / curr);
                }else{
                    st.push(prev * curr);
                }
            }
            else{
                st.push(stoi(op));
            }
        }
        return st.top();
    }
};