class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses, 0);

        for(auto neighbour : prerequisites) {
            int source = neighbour[1];
            int destination = neighbour[0];
            adjList[source].push_back(destination);
            inDegree[destination]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> linearOrder;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            linearOrder.push_back(node);

            for(auto it : adjList[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return linearOrder.size() ==  numCourses;
    }
};