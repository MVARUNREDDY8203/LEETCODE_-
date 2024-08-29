from collections import defaultdict
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        discarded = set()
        x_adj = defaultdict(list)
        y_adj = defaultdict(list)

        for i,(x, y) in enumerate(stones):
            x_adj[x].append(i)
            y_adj[y].append(i)
        
        def dfs(i):
            if i not in discarded:
                discarded.add(i)

                for neighbour in x_adj[stones[i][0]]:
                    dfs(neighbour)
                for neighbour in y_adj[stones[i][1]]:
                    dfs(neighbour)

        cnt = 0
        for i in range(len(stones)):
            if i not in discarded:
                dfs(i)
                cnt += 1

        return len(stones) - cnt