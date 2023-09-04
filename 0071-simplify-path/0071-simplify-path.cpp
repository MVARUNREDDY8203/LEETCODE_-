class Solution {
public:
    string simplifyPath(string raw_path) {
        string temp = "";
        deque<string> dque;

        string path = "";
        path += raw_path[0];
        for(int i=1; i<raw_path.size(); i++){
            if(raw_path[i-1] == '/' && raw_path[i] == '/') continue;
            path += raw_path[i];
        }
        path += "/";
        cout<<path<<endl;

        for(int i=0; i<path.size(); i++){

            if(path[i] == '/'){
                if(temp == ".."){
                    if(!dque.empty()) dque.pop_back();
                    temp = "";
                    continue;
                }
                if(temp == "."){
                    temp = "";
                    continue;
                }

                if(temp != "") dque.push_back(temp);
                temp = "";
                continue;
            }
            temp+=path[i];
        }
        string ans = "";
        
        if(dque.empty()) return "/";
        while(!dque.empty()){
            cout<<dque.front()<<" ";
            ans+="/"+dque.front();
            dque.pop_front();
        }

        return ans;
    }
};