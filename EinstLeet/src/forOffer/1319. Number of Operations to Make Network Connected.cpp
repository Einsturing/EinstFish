//难度-中毒
//简单并查集题，差不多能盲打并查集了
class UnionSet {
public:
    vector<int> parent;
    int setCnt;
    UnionSet(int n): setCnt(n){
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
        setCnt--;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size < n - 1) return -1;
        UnionSet us(n);
        for(auto connection : connections) {
            us.Union(connection[0], connection[1]);
        }
        return us.setCnt - 1;
    }
};