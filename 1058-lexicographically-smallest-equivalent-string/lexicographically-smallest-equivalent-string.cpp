class DisjointSet {
    vector<int> parent, size;
public:
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
      
     if(ultimateParent_u < ultimateParent_v) {
        parent[ultimateParent_v] = ultimateParent_u;
        size[ultimateParent_u] += size[ultimateParent_v];
     } else {
        parent[ultimateParent_u] = ultimateParent_v;
        size[ultimateParent_v] += size[ultimateParent_u];
     }
   }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i = 0; i < s1.length(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            ds.unionBySize(u , v);
        }

        for(int i = 0; i < baseStr.length(); i++) {
            baseStr[i] =  ds.findUltimateParent(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }
};