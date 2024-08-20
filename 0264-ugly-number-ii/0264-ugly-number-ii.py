import heapq
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        min_heap = []
        seen_nos = set()
        prime_factors = [2,3,5]

        heapq.heappush(min_heap, 1)
        seen_nos.add(1)

        curr_ugly = 1
        for _ in range(n):
            curr_ugly = heapq.heappop(min_heap)

            for prime in prime_factors:
                next_ugly = curr_ugly * prime
                if next_ugly not in seen_nos:
                    heapq.heappush(min_heap, next_ugly)
                    seen_nos.add(next_ugly)
        
        return curr_ugly