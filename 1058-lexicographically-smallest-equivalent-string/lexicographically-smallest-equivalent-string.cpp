class disjointSet {
    vector<int> parent;
    vector<int> size;
public: 
    disjointSet(int k) {
        parent.resize(k);
        size.resize(k, 1);
        for(int i = 0; i < k; i++) {
            parent[i] = i;
        }
    }

    int findUltimateParent(int child) {
        if(child == parent[child]) return child;
        return parent[child] = findUltimateParent(parent[child]); 
        // parent[child] is for path compression **always remember from now on. 
    }
    
    void unionFind(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if(ultimateParent_u == ultimateParent_v) return ;
        if(ultimateParent_u > ultimateParent_v) {
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        /*
           given : s1, s2, baseStr
           s1 = "parker"
           s2 = "morris"
           baseStr = "parser"
           Union both the strings according to the numeric ASCII Value
           and then for the answer part we can use the ultimateParentFind 
           to get the smaller letter first.
        */
        int n = s1.length();
        disjointSet obj(26);
        for(int i = 0; i < n; ++i) 
            obj.unionFind(s1[i] - 'a', s2[i] - 'a');

        int m = baseStr.length();
        string sortedString;
        for(int i = 0; i < m; ++i) {
            int letter = baseStr[i] - 'a';
            int ultimateParent_letter = obj.findUltimateParent(letter);
            sortedString += ultimateParent_letter + 'a';
        }   
        return sortedString;
    }
};