class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor) {
        // base case
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != originalColor)
            return;

        image[sr][sc] = color;
        dfs(image, sr - 1, sc, color, originalColor);
        dfs(image, sr + 1, sc, color, originalColor);
        dfs(image, sr, sc - 1, color, originalColor);
        dfs(image, sr, sc + 1, color, originalColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        int originalColor = image[sr][sc];

        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                dfs(image, sr, sc, color, originalColor);
            }
        }
        return image;
    }
};