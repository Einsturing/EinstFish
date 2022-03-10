//难度-中等
//哈希表+并查集
class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int index) {
        if(parent[index] != index) parent[index] = Find(parent[index]);
        return parent[index];
    }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root2] = root1;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> etoID;
        map<string, string> etoName;
        int id = 0;
        for(auto& account : accounts) {
            string& name = account[0];
            int size = account.size();
            for(int i = 1; i < size; i++) {
                string& email = account[i];
                if(!etoID.count(email)) {
                    etoID[email] = id++;
                    etoName[email] = name;
                } 
            }
        }
        UnionSet us(id);
        for(auto& account : accounts) {
            string& email1 = account[1];
            int id1 = etoID[email1];
            int size = account.size();
            for(int i = 2; i < size; i++) {
                string& email2 = account[i];
                int id2 = etoID[email2];
                us.Union(id1, id2);
            }
        }
        map<int, vector<string>> IDtoEmails;
        for(auto& [email, _] : etoID) {
            int id = us.Find(etoID[email]);
            vector<string>& account = IDtoEmails[id];
            account.emplace_back(email);
            IDtoEmails[id] = account;
        }
        vector<vector<string>> res;
        for(auto& [_, emails] : IDtoEmails) {
            sort(emails.begin(), emails.end());
            string& name = etoName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for(auto& email : emails) account.emplace_back(email);
            res.emplace_back(account);
        }
        return res;
    }
};