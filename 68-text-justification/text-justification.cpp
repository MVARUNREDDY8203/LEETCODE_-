class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l = 0, r = 0, n = words.size(), curr_size = 0;
        vector<string> ans;
        for (int r = 0; r < n; r++) {
            curr_size += words[r].size();

            if (curr_size > maxWidth) {
                // for l = 0 to r -1; r-- continue;
                string one_line = "";

                curr_size -= words[r].size();
                int space_cnt = r - l;  // removing the number of spaces
                curr_size -= space_cnt;
                int rem_space = maxWidth - curr_size;
                space_cnt--;

                cout<<l<<" "<<r<<" "<<rem_space<<" "<<space_cnt<<" "<<endl;
                if (space_cnt == 0) {
                    //meaning only 1 word is possible in the line
                    one_line += words[l++];
                    while (one_line.size() < maxWidth) one_line += " ";
                                        
                }else {
                    
                    int space_ceil = space_cnt == 0 ? 1 : ceil((float)rem_space/(float)space_cnt);
                    cout<<space_ceil<<endl;
                    int space_floor = space_cnt == 0 ? 1 : rem_space/space_cnt;
                    string ceil_spaces = "";
                    string floor_spaces = "";
                    for (int k=0; k<space_ceil; k++) ceil_spaces += " ";
                    for (int k=0; k<space_floor; k++) floor_spaces += " ";
                    
                    int spaces_added = 0;
                    int ceil_spaces_cnt = rem_space % space_cnt;
                    while (l < r) {
                        one_line += words[l++];
                        if (l == r) break;

                        if (spaces_added >= ceil_spaces_cnt) one_line += floor_spaces;
                        else {
                            one_line += ceil_spaces;
                            spaces_added++;
                        }
                    }
                }

                ans.push_back(one_line);

                curr_size = words[r].size();
            }
            curr_size++;    // minimum 1 space
        }
        // push_back the last line
        string last_line = "";

        while (l < n) {
            last_line += words[l++];
            if (last_line.size() < maxWidth) last_line += ' ';
        }
        int remn_spaces = maxWidth - last_line.size();
        while (remn_spaces > 0) {
            last_line += ' ';
            remn_spaces--;
        }
        ans.push_back(last_line);

        return ans;
    }
};