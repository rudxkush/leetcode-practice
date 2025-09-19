class Solution {
public:
    int res = 1;
    int dfs(vector<vector<int>>& graph, int node, int parent, string& s) {
        int longest = 0, secondLongest = 0;

        for(auto nei : graph[node]) {
            if(nei == parent) continue;
            int len = dfs(graph, nei, node, s);

            if (s[nei] == s[node]) continue;
        
            // maintain longest and secondLongest
            if (len > secondLongest) {
                secondLongest = len;
            }

            if (secondLongest > longest) {
                swap(longest, secondLongest);
            }
        }

        int temp = 1 + longest + secondLongest;

        int ans = 1 + longest;

        res = max({res, temp, ans});

        return ans;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                graph[parent[i]].push_back(i);
                graph[i].push_back(parent[i]);
            }
        }

        dfs(graph, 0, -1, s);
        return res;
    }
};

