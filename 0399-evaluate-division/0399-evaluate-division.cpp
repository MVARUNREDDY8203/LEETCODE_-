class Solution {
public:
    unordered_map<string, unordered_map<string, double>> gr;
    void graph_plotter(vector<vector<string>> &eqns, vector<double>& values) {
        for (int i=0; i<eqns.size(); i++) {
            string divisor = eqns[i][0];
            string dividend = eqns[i][1];
            gr[divisor][dividend] = values[i];
            gr[dividend][divisor] = 1.0/values[i];
        }
    }

    void dfs(unordered_map<string, unordered_map<string, double>> &gr, unordered_set<string> &vis, string node, string &dest, double &ans, double temp) {
        if (vis.find(node) != vis.end()) return;
        vis.insert(node);
        if (node == dest) {
            ans = temp;
            return;
        }
        for (auto i: gr[node]) {
            dfs(gr, vis, i.first, dest, ans, temp*i.second);
        }
    }

    void query_processor(unordered_map<string, unordered_map<string, double>> &gr, vector<vector<string>> &queries, vector<double> &final_ans) {
        for (auto query: queries) {
            double ans = -1;
            if (gr.find(query[0]) == gr.end() || gr.find(query[1]) == gr.end()) {
                ans = -1;
            }
            else {
                unordered_set<string> vis;
                dfs(gr, vis, query[0], query[1], ans, 1.0);
            }
            final_ans.push_back(ans);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph_plotter(equations, values);
        vector<double> final_ans;
        query_processor(gr, queries, final_ans);
        return final_ans;
    }
};