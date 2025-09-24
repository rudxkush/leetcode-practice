class Solution {
public:
    int totalNodes = 0;
    void dfs1(vector<vector<int>>& tree, vector<int>& noOfNodes, int node, int parent) {
        for(auto nei : tree[node]) {
            if(nei == parent) continue;
            dfs1(tree, noOfNodes, nei, node);
            noOfNodes[node] += noOfNodes[nei];
        }
        noOfNodes[node] += 1;
    }
    int dfs2(vector<vector<int>>& tree, int node, int parent, int depth) {
        int count = depth;
        for(auto nei : tree[node]) {
            if(nei == parent) continue;     
            count += dfs2(tree, nei, node, depth+1);
        }
        return count;
    }
    void dfs3(vector<vector<int>>& tree, vector<int>& ans, 
              vector<int>& noOfNodes, int node, int parent) {
        for(auto nei : tree[node]) {
            if(nei == parent) continue;
            ans[nei] = ans[node] + (totalNodes - noOfNodes[nei]) - noOfNodes[nei];
            dfs3(tree, ans, noOfNodes, nei, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Building Tree here!
        vector<vector<int>> tree(n);
        for (auto edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n, 0);
        vector<int> noOfNodes(n, 0);

        // For getting the size of every subtree in the tree.
        dfs1(tree, noOfNodes, 0,-1);
        // For getting the ans for the root. 
        // Assuming root as my parent.
        ans[0] = dfs2(tree, 0, -1, 0); 
        // For getting the ans for the rest of the tree.
        totalNodes = n;
        dfs3(tree, ans, noOfNodes, 0, -1); 
        return ans;
    }
};