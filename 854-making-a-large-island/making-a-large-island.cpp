class DisjointSet {
public:
    vector<int> parent, size;
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // path compression
    int findUltimateParent(int node) {
        if(node == parent[node])
            return node;
            
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);
      
        if(ultimateParent_u == ultimateParent_v) return;
      
        if(size[ultimateParent_u] < size[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v; 
            size[ultimateParent_v] += size[ultimateParent_u];
        } else {
            parent[ultimateParent_v] = ultimateParent_u; 
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        DisjointSet ds(r*c);
        
        int directions[4][2] = {{0, 1},
                                {0, -1},
                                {1, 0},
                                {-1, 0}};
        
        // Step 1: Create disjoint sets for existing land cells
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 0) continue;

                for(auto dir : directions) {
                    int adjRow = i + dir[0];
                    int adjCol = j + dir[1];
                    
                    if(adjRow >= 0 && adjRow < r 
                    && adjCol >= 0 && adjCol < c
                    && grid[adjRow][adjCol] == 1) {
                        int node = i * c + j;
                        int adjNode = adjRow * c + adjCol;
                        if(ds.findUltimateParent(node) == ds.findUltimateParent(adjNode)) continue;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        
        // Step 2: Find the largest island
        int maxSize = 0;
        
        // First, get the size of the largest existing island
        for(int i = 0; i < r * c; i++) {
            if(ds.parent[i] == i && i / c < r && i % c < c && grid[i / c][i % c] == 1) {
                maxSize = max(maxSize, ds.size[i]);
            }
        }
        
        // Handle the case where the grid is all 1s
        if(maxSize == r * c) return maxSize;
        
        // Try changing each 0 to 1
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == 1) continue;
                
                unordered_set<int> components;
                int sizeSum = 1;  // Start with 1 for the current cell
                
                for(auto dir : directions) {
                    int adjRow = i + dir[0];
                    int adjCol = j + dir[1];
                    
                    if(adjRow >= 0 && adjRow < r 
                    && adjCol >= 0 && adjCol < c
                    && grid[adjRow][adjCol] == 1) {  // Check for adjacent land cells
                        int adjNode = adjRow * c + adjCol;
                        int parentNode = ds.findUltimateParent(adjNode);
                        
                        if(components.find(parentNode) == components.end()) {
                            components.insert(parentNode);
                            sizeSum += ds.size[parentNode];
                        }
                    }
                }
                
                maxSize = max(maxSize, sizeSum);
            }
        }
        
        // Handle the case where the grid is all 0s
        return maxSize == 0 ? 1 : maxSize;
    }
};