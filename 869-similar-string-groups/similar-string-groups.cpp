/*
    Two strings - x, y are identical provided
    - Both the strings match
    - At most one swapped is allowed to make them a complete match.
*/
class disjointSet {
    vector<int> parent;
    vector<int> size;

public:
    disjointSet(int k) {
        parent.resize(k);
        size.resize(k, 1);
        for (int i = 0; i < k; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int child) {
        if (child == parent[child])
            return child;
        return parent[child] = findUltimateParent(parent[child]);
        // parent[child] is for path compression **always remember from now on.
    }

    void unionFind(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;

        // Union by size
        if (size[ultimateParent_u] < size[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        } else {
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }

    int getGroupCount() {
        int count = 0;
        for (int i = 0; i < parent.size(); ++i)
            if (parent[i] == i)
                count++;
        return count;
    }
};

class Solution {
public:
    bool isSimilar(string& s1, string& s2) {
        if (s1.length() != s2.length())
            return false;

        vector<int> diff;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
                if (diff.size() > 2)
                    return false;
            }
        }

        if (diff.empty())
            return true;

        return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] &&
               s1[diff[1]] == s2[diff[0]];
    }

    // void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    //     visited[node] = true;
    //     for (int neighbor : graph[node]) {
    //         if (!visited[neighbor]) {
    //             dfs(neighbor, graph, visited);
    //         }
    //     }
    // }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        disjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    // graph[i].push_back(j);
                    // graph[j].push_back(i);
                    ds.unionFind(i, j);
                }
            }
        }

        // basically the third step is this :
        // int groupCount = 0;
        // for (int i = 0; i < n; ++i)
        //     if (parent[i] == i)
        //         groupCount++;
        // return groupCount;

        return ds.getGroupCount(); // cleaned up in DSU class
    }
};
