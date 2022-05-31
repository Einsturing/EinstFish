//难度-困难
//拓扑排序+dfs
class Solution {
public:
    unordered_map<char, vector<char>> edges;
    unordered_map<char, int> states;
    bool valid = true;
    string ans;
    int idx;
    string alienOrder(vector<string>& words) {
        int len = words.size();
        for(string& word : words) {
            int wordlen = word.size();
            for(int j = 0; j < wordlen; j++) {
                char c = word[j];
                if(!edges.count(c)) edges[c] = vector<char>();
            }
        }
        for(int i = 1; i < len && valid; i++) addEdge(words[i - 1], words[i]);
        ans = string(edges.size(), ' ');
        idx = edges.size() - 1;
        for(auto [u, v] : edges) if(!states.count(u)) dfs(u);
        if(!valid) return "";
        return ans;
    }
    void addEdge(string from, string to) {
        int len1 = from.size();
        int len2 = to.size();
        int minlen = min(len1, len2);
        int id = 0;
        while(id < minlen) {
            char c1 = from[id];
            char c2 = to[id];
            if(c1 != c2) {
                edges[c1].emplace_back(c2);
                break;
            }
            id++;
            if(id == minlen && len1 > len2) valid = false;
        }
    }
    void dfs(char u) {
        states[u] = 1;
        for(char v : edges[u]) {
            if(!states.count(v)) {
                dfs(v);
                if(!valid) return;
            }
            else if(states[v] == 1) {
                valid = false;
                return;
            }
        }
        states[u] = 2;
        ans[idx--] = u;
    }
};