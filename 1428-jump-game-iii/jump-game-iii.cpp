class Solution {
public:
    vector<bool> visited;
    bool solve(vector<int>& arr, int start) {
        // out of bound
        if(start >= arr.size() || start < 0) return false;
        if(arr[start] == 0) return true;
        if(visited[start]) return false;

        visited[start] = true;

        return solve(arr, start + arr[start]) || solve(arr, start - arr[start]);
    }
    bool canReach(vector<int>& arr, int start) {
        visited.assign(arr.size(), false);
        return solve(arr, start);
    }
};