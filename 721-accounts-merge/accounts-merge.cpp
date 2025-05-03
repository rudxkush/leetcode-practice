class DisjointSet {
public:
    vector<int> parent, size;
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // path compression
    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;

        if (size[ultimateParent_u] < size[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        } else {
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        DisjointSet ds(accounts.size());

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    ds.unionBySize(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(accounts.size());

        for (auto it : mp) {
            int node = ds.findUltimateParent(it.second);
            string mail = it.first;

            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); i++) {
            if (mergedMails[i].empty())
                continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> tmp;
            tmp.push_back(accounts[i][0]);
            for (auto it : mergedMails[i]) {
                tmp.push_back(it);
            }
            res.push_back(tmp);
        }
        return res;
    }
};