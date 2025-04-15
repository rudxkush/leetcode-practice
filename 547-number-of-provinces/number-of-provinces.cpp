class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int srcNode, vector<bool>& visited) {
        visited[srcNode] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[srcNode][i] && !visited[i]) {
                dfs(isConnected, i, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }
};