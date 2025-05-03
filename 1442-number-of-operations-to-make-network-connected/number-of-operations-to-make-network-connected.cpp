class DisjointSet {
public:
    vector<int> parent, size;
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0;i < n;i++) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // count the number of extra nodes while building the graph (dynamic graph)
        DisjointSet ds(n);
        int extraCount = 0;
        for(auto connect : connections) {
            int u = connect[0]; 
            int v = connect[1];

            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)) {
                extraCount++;
            } else {
                ds.unionBySize(u, v);
            }
        }
        // count the components using parent vector
        int numberOfcomponents = 0;
        for(int i = 0; i < n; i++) {
            if(i == ds.parent[i]) {
                numberOfcomponents++;
            }
        }
        if(extraCount >= numberOfcomponents - 1) return numberOfcomponents - 1;
        else return -1;
    }
};