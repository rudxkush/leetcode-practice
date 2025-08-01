/*
    Two strings - x, y are identical provided
    - Both the strings match
    - Atmost one swapped is allowed to make them a complete match.
*/
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

        return diff.size() == 2 &&
               s1[diff[0]] == s2[diff[1]] &&
               s1[diff[1]] == s2[diff[0]];
    }

    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int groupCount = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                groupCount++;
            }
        }

        return groupCount;
    }
};
