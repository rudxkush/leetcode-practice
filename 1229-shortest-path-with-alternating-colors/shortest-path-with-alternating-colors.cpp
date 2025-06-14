class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n);
        for(auto edge : redEdges) { redGraph[edge[0]].push_back(edge[1]); }
        for(auto edge : blueEdges) { blueGraph[edge[0]].push_back(edge[1]); }
        vector<int> res(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));   // visited -> red, blue

        queue<tuple<int, int, int>> q; // node, distance, prevColor (prevColor : start = -1, red = 0, blue = 1)
        q.push({0, 0, -1});
        visited[0][0] =  visited[0][1] = true;
        while(!q.empty()) {
            auto[node, dis, prevCol] = q.front();
            q.pop();

            if(res[node] == -1) res[node] = dis;

            if(prevCol != 0) {  // if previous was not red
                for(auto adjNode : redGraph[node]) {
                    if(!visited[adjNode][0]) {
                        visited[adjNode][0] = true;
                        q.push({adjNode, dis + 1, 0});
                    }
                }
            }
            if(prevCol != 1) {  // if previous was not blue
                for(auto adjNode : blueGraph[node]) {
                    if(!visited[adjNode][1]) {
                        visited[adjNode][1] = true;
                        q.push({adjNode, dis + 1, 1});
                    }
                }
            }
        }
        return res;
    }
};