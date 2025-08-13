class Solution {
private: 
    // DFS helper to search from 'curr' to 'target'
    // 'value' stores the running product of edge weights so far
    bool dfs(string& curr, string& target, double value, double& result,
             unordered_map<string, vector<pair<string, double>>>& graph,
             unordered_map<string, bool>& visited) {
        
        // Base case: reached target
        if(curr == target) {
            result = value;
            return true;
        }        

        visited[curr] = true; // mark as visited

        // Explore all neighbors
        for(auto& [neighbour, val] : graph[curr]) {
            if(!visited[neighbour]) {
                // Multiply value with edge weight and recurse
                if(dfs(neighbour, target, value * val, result, graph, visited))
                    return true; // stop search if found
            }
        }    
        return false; // path not found
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                 vector<double>& values, 
                                 vector<vector<string>>& queries) {
        
        // Step 1: Build graph from equations
        // Each equation a/b = k is stored as:
        //   a -> (b, k)
        //   b -> (a, 1/k)
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans; // final results for each query

        // Step 2: Process each query
        for(auto& query : queries) {
            
            // Case 1: either variable not present in graph
            if(!graph.count(query[0]) || !graph.count(query[1])) {
                ans.push_back(-1.0);
                continue; // skip DFS
            }

            // Case 2: same variable divided by itself (must be 1)
            if(query[0] == query[1]) {
                ans.push_back(1.0);
                continue; // skip DFS
            }

            // Step 3: Run DFS to find a path and compute division
            unordered_map<string, bool> visited;
            double result = -1.0; // default if no path found
            dfs(query[0], query[1], 1.0, result, graph, visited);
            ans.push_back(result);
        }

        return ans;
    }
};

/*
Example walkthrough:
    equations = [["a", "b"], ["b", "c"]]
    values = [2.0, 3.0]
    => a/b = 2.0 , b/c = 3.0
       So graph:
         a -> (b, 2.0)
         b -> (a, 0.5), (c, 3.0)
         c -> (b, 1/3)

    queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
    Expected:
      a / c = a/b * b/c = 2 * 3 = 6.0
      b / a = 1 / (a / b) = 0.5
      a / e = -1 (e not in graph)
      a / a = 1
      x / x = -1 (x not in graph)
    Output: [6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
*/
