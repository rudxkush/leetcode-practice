class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pQ;

        vector<vector<int>> res;

        for (int i = 0; i < points.size(); i++) {
            int y = points[i][1];
            int x = points[i][0];
            int distance = x*x + y*y;

            pQ.push({distance, {x, y}});

            if (pQ.size() > k) {
                pQ.pop();
            }
        }

        while (!pQ.empty()) {
            pair<int, int> point = pQ.top().second;
            res.push_back({point.first, point.second});
            pQ.pop();
        }

        return res;
    }
};