class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        //  reverse edge
        vector<vector<pair<int, int>>> inverseGraph(n);
         for (auto &edge : edges) {
            inverseGraph[edge[1]].push_back({edge[2], edge[0]});
        }
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pQ; // {weight, node}

        /*
            The threshold is just a dummy variable , think if any node is unreachable 
            from 0 then return -1 , else it just need one parent to become reachable from 0,
            (in original graph this mean only one outgoing edge is needed at most to get 0). 
            So why need 2 or k edges
        */

        int maxPresentInMst = 0;
        vector<bool> visited(n, false);
        pQ.push({0, 0});

        while(!pQ.empty()) {
            auto [wt, node] = pQ.top(); pQ.pop();
            if (visited[node]) continue;
            visited[node] = true;
            maxPresentInMst = max(maxPresentInMst, wt);

            for(auto [neiWt, nei] : inverseGraph[node]) {
                if(!visited[nei]) {
                    pQ.push({neiWt, nei});
                }
            }
        }

        for (int visit : visited) if (!visit) return -1;
        return maxPresentInMst;
    }
};