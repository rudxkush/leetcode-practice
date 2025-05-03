class DisjointSet {
public:
    vector<int> parent, size;
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0;i <= n; i++) {
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
      
     if(ultimateParent_u == ultimateParent_v) return ;
      
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        vector<int> parent(V + 1), size(V + 1, 1); 
        for(int i = 0; i <= V; i++) {
            parent[i] = i;
        }

        DisjointSet ds(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1) {
                    ds.unionBySize(i + 1, j + 1);
                }
            }
        }

        int count = 0;
        for(int i = 1; i <= V; i++) {
            if(ds.parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};