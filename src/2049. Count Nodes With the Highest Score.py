# 难度-中等
# 统计最高分的节点数目，dfs
class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        child = [[] for _ in range(n)]
        for node, p in enumerate(parents):
            if p != -1:
                child[p].append(node)

        maxscore, cnt = 0, 0
        
        def dfs(node):
            score = 1
            sum = 1
            for c in child[node]:
                sz = dfs(c)
                score *= sz
                sum += sz
            if node != 0:
                score *= n - sum
            nonlocal maxscore, cnt
            if maxscore == score:
                cnt += 1
            elif maxscore < score:
                maxscore = score
                cnt = 1
            return sum
        
        dfs(0)
        return cnt