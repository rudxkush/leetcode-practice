class Solution {
public:
    int spanningTree(int n, vector<vector<pair<int,int>>>& adj) {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> minHeap;
                       
        vector<bool> visited(n, false);
        minHeap.push({0, 0});
        int mstSum = 0;
        
        while(!minHeap.empty()) {
            int weight = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            
            if(visited[node]) continue;
            visited[node] = true;
            mstSum += weight;
            
            for(auto neighbour : adj[node]) {
                int v = neighbour.first;
                int wt = neighbour.second;
                if(!visited[v]) {
                    minHeap.push({wt, v});
                }
            }
        }
        return mstSum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        return spanningTree(n, adj);
    }
};
