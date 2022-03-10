//难度-困难
//并查集，把每对情侣当成一个点，如果坐混了就连一条边，连通分量的大小减1就是要交换的次数(情人节给单身狗这种题面？爬爬爬)
class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n): parent(n) { iota(parent.begin(), parent.end(), 0); }
    int Find(int index) { return parent[index] == index ? parent[index] : parent[index] = Find(parent[index]); }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root2] = root1;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        int N = len / 2;
        UnionSet us(N);
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < len; i += 2) {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            us.Union(l, r);
        }
        for(int i = 0; i < N; i++) mp[us.Find(i)]++;
        for(auto [u, cnt] : mp) res += cnt - 1;
        return res;
    }
};