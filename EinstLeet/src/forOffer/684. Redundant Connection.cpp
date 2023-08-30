//难度-中等
//图论题，去除图中一边使其无环路，并查集可解
class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if(parent[index] != index) parent[index] = Find(parent, parent[index]);
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) { parent[Find(parent, index1)] = Find(parent, index2); }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodecnts = edges.size();
        vector<int> parent(nodecnts + 1);
        for(int i = 1; i <= nodecnts; i++) parent[i] = i;
        for(auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            if(Find(parent, node1) != Find(parent, node2)) Union(parent, node1, node2);
            else return edge;
        }
        return vector<int> {};
    }
};