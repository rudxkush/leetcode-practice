class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int directions[4][2] = {{-1, 0},  {0, 1},  {1, 0},  {0, -1}};
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> minHeap;

        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> distance(r, vector<int>(c, INT_MAX));

        distance[0][0] = 0;
        minHeap.push({0, {0, 0}});
        while(!minHeap.empty()) {
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            int diff = minHeap.top().first; 
            minHeap.pop();
            if(row == r - 1 && col == c - 1) return diff;

            for(auto dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 && ncol >= 0 && nrow < r && ncol < c) {
                    int newDiff = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newDiff < distance[nrow][ncol]) {
                        distance[nrow][ncol] = newDiff;
                        minHeap.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};