class disjointSet {
    vector<int> rank, parent;
public:
    // Initializes disjoint sets
    disjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }
    // path compression
    int findUltimateParent(int node) {
        if(node == parent[node])
            return node;
            
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
      int ultimateParent_u = findUltimateParent(u);
      int ultimateParent_v = findUltimateParent(v);
      // if both have the same ultimate parent
      if(ultimateParent_u == ultimateParent_v) return ;
      
      if(rank[ultimateParent_u] < rank[ultimateParent_v]) {
        parent[ultimateParent_u] = ultimateParent_v;
      } else if(rank[ultimateParent_u] > rank[ultimateParent_v]) {
        parent[ultimateParent_v] = ultimateParent_u;
      } else { 
        // When both components have equal rank, we arbitrarily 
        // choose ultimateParent_u as the new parent and
        // increment its rank since the tree height potentially 
        // increases by 1
        parent[ultimateParent_v] = ultimateParent_u;
        rank[ultimateParent_u]++;
      }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        /*
            "a == b"
            "b != a"
            These are contradictory, so we return false.

            "b == a"
            "a == b"
            Both are consistent, so return true.

            -> The main idea is:
            1. Union all variables that are equal.
            2. Then, if any inequality exists between variables in the same set,
           it's a contradiction.
            => Return false in that case.
        */
        disjointSet obj(26);
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            if (equations[i][1] == '=')
                obj.unionByRank(equations[i][0] - 'a', equations[i][3] - 'a');
        }

        for (int i = 0; i < n; ++i) {
            if (equations[i][1] == '!')
                if (obj.findUltimateParent(equations[i][0] - 'a') == obj.findUltimateParent(equations[i][3] - 'a'))
                    return false;
        }
        return true;
    }
};