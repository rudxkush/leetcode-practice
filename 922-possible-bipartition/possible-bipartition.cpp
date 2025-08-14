class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node, vector<int>& colors, int color) {
        if(colors[node] != 0) return colors[node] == color;

        colors[node] = color;
        for(auto neighbour: graph[node]) 
            if(!dfs(graph, neighbour, colors, -color)) return false;

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);     
        for(auto dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]); // Directed Graph
            graph[dislike[1]].push_back(dislike[0]); 
        }

        vector<int> colors(n + 1, 0); // group 1 is 1 and 2 is -1
        for(int i = 1; i <= n; ++i) 
            if(colors[i] == 0)
                if(!dfs(graph, i, colors, 1)) 
                    return false;
        
        return true;
    }
};

/*

    n = 4, dislikes = [[1,2],[1,3],[2,4]]

    What the graph is gonna look like: 
        1 -> 2 -> 4
        ↓
        3

    [1, 4] -> group 1
    [3, 2] -> group 2

    Can we split them into two groups ? True
    
*/