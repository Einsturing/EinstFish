//难度-中等
//图论题，将石子的纵坐标+10000，再和横坐标用并查集合并，最后剩下的并查集数量就是石子最少的情况
const int maxn = 2e4 + 5;

class Solution {
public:

    int Find(vector<int>& parent, int index) { 
        return index == parent[index] ? index : parent[index] = Find(parent, parent[index]);
    }

    void Union(vector<int>& parent, int index1, int index2) { parent[Find(parent, index2)] = Find(parent, index1); }

    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(maxn);
        for(int i = 0; i < maxn; i++) parent[i] = i;
        for(int i = 0; i < stones.size(); i++) Union(parent, stones[i][0], stones[i][1] + 10000);
        unordered_map<int, bool> ump;
        for(int i = 0; i < stones.size(); i++) {
            ump[Find(parent, stones[i][0])] = true;
            ump[Find(parent, stones[i][1] + 10000)] = true;
        }
        return stones.size() - ump.size();
    }
};