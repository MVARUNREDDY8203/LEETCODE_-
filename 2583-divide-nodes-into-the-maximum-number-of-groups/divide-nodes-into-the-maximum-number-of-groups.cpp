class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1, vector<int>(0));

        int rep[501];
        int size[501];
        for (int i=0; i<501; i++) {
            rep[i] = i;
            size[i] = 1;
        }

        function<int(int)> find = [&](int u) -> int {
            if (rep[u] == u) return u;

            return rep[u] = find(rep[u]);
        };

        function<void(int, int)> Union = [&](int u, int v) -> void {
            u = find(u);
            v = find(v);

            if (u == v) return;

            if (size[u] < size[v]) {
                rep[u] = v;
                size[v]+= size[u];
            } else {
                rep[v] = u;
                size[u] += size[v];
            }
        };

        for (auto i: edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            Union(i[0], i[1]);
        }

        function<int(int)> get_num_grps = [&](int src) -> int {
            queue<int> que;
            vector<int> layer_seen(n+1, -1);

            que.push(src);
            layer_seen[src] = 0;
            int deepest_layer  = 0;

            while (!que.empty()) {
                int nodes_in_curr_layer = que.size();

                for (int j=0; j<nodes_in_curr_layer; j++) {
                    int curr_node = que.front();
                    que.pop();

                    for (int neighbour: graph[curr_node]) {
                        // cout<<neighbour<<" "<<layer_seen.size()<<" "<<endl;
                        if (layer_seen[neighbour] == -1) {
                            layer_seen[neighbour] = deepest_layer + 1;
                            que.push(neighbour);
                        }
                        else {
                            if (layer_seen[neighbour] == deepest_layer) return -1;
                        }
                    }
                }

                deepest_layer++;
            }

            // cout<<deepest_layer<<endl;
            return deepest_layer;
        };

        unordered_map<int, int> num_of_grps_for_component;

        for (int i=1; i<=n; i++) {
            int num_of_grps = get_num_grps(i);
            if (num_of_grps == -1) return -1;

            int root = find(i);
            num_of_grps_for_component[root] = max(num_of_grps_for_component[root], num_of_grps); 
        }

        int ans = 0;
        cout<<num_of_grps_for_component.size();
        for (int i=0; i<n; i++) cout<<rep[i]<<" ";
        for (auto i: num_of_grps_for_component) ans += i.second;
        return ans;
    }
};