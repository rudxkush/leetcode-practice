class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adjList, vector<int>& inDegree) {
        vector<int> order;
        // kahn's algorithm
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++) 
            if(inDegree[i] == 0) 
                q.push(i);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(auto& neighbour : adjList[node]) {
                inDegree[neighbour]--;   
                if(inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        return (order.size() == adjList.size()) ? order : vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //  0  1  2 3 4 5 6  7
        // -1 -1  1 0 0 1 0 -1
        for(int i = 0; i < n; i++) 
            if(group[i] == -1) 
                group[i] = m++;

        vector<vector<int>> groupGraph(m), itemGraph(n);
        vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

        for(int i = 0; i < n; i++) {
            for(auto before : beforeItems[i]) { // if the items are in the same group then 
                // connect them at item level making sure of the before relation.  
                itemGraph[before].push_back(i);
                itemIndegree[i]++;
                if(group[i] != group[before]) { // items are not in the same group then  
                // that groups should ought to connected in the order that satisfy the 
                // before relationship.
                    groupGraph[group[before]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        /// get there linear ordering.
        vector<int> groupTopoOrder = topoSort(groupGraph, groupIndegree);
        vector<int> itemTopoOrder = topoSort(itemGraph, itemIndegree);

        unordered_map<int, vector<int>> groupedItems;
        for (int item : itemTopoOrder)
            groupedItems[group[item]].push_back(item);

        // Output in sorted group order
        vector<int> result;
        for (int g : groupTopoOrder) {
            for (int item : groupedItems[g]) {
                result.push_back(item);
            }
        }

        return result;
    }
};

/*
    1203. Sort Items by Groups Respecting Dependencies. Example 1 DeCode : 
            0 1 2 3 4 5 6 7
            2 3 1 0 0 1 0 4

            Clustered items as given
            0 --> {3, 4, 6}
            1 --> {2, 5}
            2 --> {0}
            3 --> {1}
            4 --> {7}

            order according to there relationship
            3 1 2 4 0 

            get the order -> topoSort

            now it is time to sort the items according to the given relationship
            get the order -> toposort

            return the cycle if there was never a cycle detected.
*/