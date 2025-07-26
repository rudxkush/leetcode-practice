class Solution {
public:
    vector<vector<bool>> isVisited;

    bool check(int x, int y, int target, int capX, int capY) {
        if (x + y == target) return true;
        if (isVisited[x][y]) return false;
        isVisited[x][y] = true;

        bool isReachingTarget = false;

        // Fill either jug completely
        isReachingTarget = isReachingTarget || check(capX, y, target, capX, capY); // Fill x
        isReachingTarget = isReachingTarget || check(x, capY, target, capX, capY); // Fill y

        // Empty either jug
        isReachingTarget = isReachingTarget || check(0, y, target, capX, capY);
        isReachingTarget = isReachingTarget || check(x, 0, target, capX, capY);

        // Pour x -> y
        int pourXtoY = min(x, capY - y);
        isReachingTarget = isReachingTarget || check(x - pourXtoY, y + pourXtoY, target, capX, capY);

        // Pour y -> x
        int pourYtoX = min(y, capX - x);
        isReachingTarget = isReachingTarget || check(x + pourYtoX, y - pourYtoX, target, capX, capY);

        return isReachingTarget;
    }

    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        isVisited.assign(x + 1, vector<bool>(y + 1, false));
        return check(0, 0, target, x, y); // Start from (0, 0)
    }
};
