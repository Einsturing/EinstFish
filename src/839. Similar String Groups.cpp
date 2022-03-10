//难度-困难
//每个字符串当成节点，相似则有一条边，跑个并查集，返回连通分量数目
class UnionSet {
public:
    vector<int> parent;
    int cnt;
    UnionSet(int n): parent(n), cnt(n) { iota(parent.begin(), parent.end(), 0); }
    int Find(int index) { return parent[index] == index ? parent[index] : parent[index] = Find(parent[index]); }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root2] = root1;
        cnt--;
    }
    bool connected(int index1, int index2) { return Find(index1) == Find(index2); }
};
class Solution {
public:
    bool similar(string a, string b, int len) {
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(a[i] != b[i]) {
                cnt++;
                if(cnt > 2) return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        UnionSet us(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(us.connected(i, j)) continue;
                if(similar(strs[i], strs[j], len)) us.Union(i, j);
            }
        }
        return us.cnt;
    }
};