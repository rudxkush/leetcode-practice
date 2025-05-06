class DisjointSet {
    vector<int> parent, size;
public:
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0;i <= n;i++) {
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
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        int minScore = INT_MAX;

        for(auto road : roads) {
            ds.unionBySize(road[0], road[1]);
        }

        int parentOfroot = ds.findUltimateParent(1);

        for(auto road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            if(ds.findUltimateParent(u) == parentOfroot) {
                minScore = min(wt, minScore);
            }
        }
        return minScore;
    }
};

