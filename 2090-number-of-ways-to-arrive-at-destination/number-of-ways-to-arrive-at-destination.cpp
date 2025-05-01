class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // creating adjacency list
        vector<vector<pair<int, int>>> adjList(n);
        for(auto road : roads) {
            int source = road[0];
            int destination = road[1];
            int weight = road[2];

            adjList[source].push_back({destination, weight});
            adjList[destination].push_back({source, weight});
        }
        // distance between the src and the ith node
        vector<long long> distance(n, LLONG_MAX);

        // using min heap to precure the shortest from top
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> minHeap;

        // ways we can reach the adj nodes from the src
        vector<int> ways(n, 0);
        int mod = (int) (1e9 + 7);

        distance[0] = 0; 
        ways[0] = 1; // that is one way to reach the src node
        // {distance, node}
        minHeap.push({0, 0});

        while(!minHeap.empty()) {
            int node = minHeap.top().second;
            long long currDistance = minHeap.top().first;
            minHeap.pop();

            for(auto neighbour : adjList[node]) {
                int adjNode = neighbour.first; 
                int adjWeight = neighbour.second;

                long long newDist = currDistance + adjWeight;
                if(newDist < distance[adjNode]) {
                    distance[adjNode] = newDist;
                    minHeap.push({distance[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } else if(newDist == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};