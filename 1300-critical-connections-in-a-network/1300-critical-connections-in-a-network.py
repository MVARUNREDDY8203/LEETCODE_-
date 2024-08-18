class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        self.adj = [[] for _ in range(n)]
        self.disc = [float('inf')] * n
        self.processed = [0] * n
        self.critical_conns = []

        for u,v in connections:
            self.adj[u].append(v)
            self.adj[v].append(u)
        
        def dfs(i: int, depth: int) -> int:
            if self.disc[i] < depth:
                return self.disc[i]
            
            self.disc[i] = depth
            min_depth = depth
            
            for j in self.adj[i]:
                if self.disc[j] != depth - 1 and self.processed[j] == 0: # not the parent and not been processed:
                    curr_min_depth = dfs(j, depth + 1)
                    if curr_min_depth > depth:
                        # bridging edge has been found
                        self.critical_conns.append([i, j])
                    min_depth = min(min_depth, curr_min_depth)
            
            self.processed[i] = 1
            return min_depth

        dfs(0, 1)
        return self.critical_conns

