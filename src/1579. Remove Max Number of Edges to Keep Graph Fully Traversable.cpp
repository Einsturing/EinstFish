//难度-困难
//并查集，先证明公共边比单独边最优，然后再遍历每条边，合并失败说明这条边可删除
class UnionSet {
public:
    vector<int> parent;
    int cnt;
    UnionSet(int n): cnt(n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int index) {
        if(parent[index] != index) return parent[index] = Find(parent[index]);
        return parent[index];
    }
    bool Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return false;
        parent[root2] = root1;
        --cnt;
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int res = 0;
        UnionSet u_alice(n), u_bob(n);
        for(auto& e : edges) {
            e[1]--;
            e[2]--;
        }
        for(const auto& e : edges) {
            if(e[0] == 3) {
                if(!u_alice.Union(e[1], e[2])) ++res;
                else u_bob.Union(e[1], e[2]);
            }
        }
        for(const auto& e : edges) {
            if(e[0] == 1) {
                if(!u_alice.Union(e[1], e[2])) res++;
            }
            else if(e[0] == 2) {
                if(!u_bob.Union(e[1], e[2])) res++;
            }
        }
        if(u_alice.cnt != 1 || u_bob.cnt != 1) return -1;
        return res;
    }
};