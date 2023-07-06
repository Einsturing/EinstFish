//难度-中等
//并查集，重点是如何想到把单元格分成四个节点进行并查集操作
class UnionSet {
public:
    vector<int> parent;
    int count;
    UnionSet(int n): count(n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int index) {
        if(parent[index] != index) return parent[index] = Find(parent[index]);
        return parent[index];
    }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root2] = root1;
        count--;
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        int size = 4 * N * N;
        UnionSet us(size);
        for(int i = 0; i < N; i++) {
            string row = grid[i];
            for(int j = 0; j < N; j++) {
                int id = 4 * (i * N + j);
                char c = row[j];
                if(c == '/') {
                    us.Union(id, id + 3);
                    us.Union(id + 1, id + 2);
                }
                else if(c == '\\') {
                    us.Union(id, id + 1);
                    us.Union(id + 2, id + 3);
                }
                else {
                    us.Union(id, id + 1);
                    us.Union(id + 1, id + 2);
                    us.Union(id + 2, id + 3);
                }
                if(j + 1 < N) us.Union(id + 1, 4 * (i * N + j + 1) + 3);
                if(i + 1 < N) us.Union(id + 2, 4 * ((i + 1) * N + j));
            }
        }
        return us.count;
    }
};