class Solution {
public:
    int maxTime = INT_MIN;
    void dfs(unordered_map<int, vector<int>>& tree, vector<int>& informTime, int headID, int currTime) {
        maxTime = max(currTime, maxTime);

        for(int adj : tree[headID]) {
            dfs(tree, informTime, adj, currTime + informTime[headID]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> tree;
        for(int i = 0; i < manager.size(); i++) {

            if(manager[i] != -1) 
                tree[manager[i]].push_back(i);
        }
        dfs(tree, informTime, headID, 0);
        return maxTime;
    } 
};


/*

      n employees : 0 to n - 1
      head -> headhID
      Each employee -> one direct manager -> manager arr[i]
      manager[headID] = -1

*/