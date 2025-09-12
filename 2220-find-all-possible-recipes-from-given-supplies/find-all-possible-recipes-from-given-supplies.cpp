class Solution {
public:
    static vector<string> findAllRecipes(vector<string>& recipes,
                                         vector<vector<string>>& ingredients,
                                         vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> sup(supplies.begin(), supplies.end());
        vector<int> inDegree(n, 0);
        unordered_map<string, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            for (const string& s : ingredients[i]) {
                if (!sup.count(s)) {
                    adj[s].push_back(i);
                    inDegree[i]++;
                }
            }
        }

        int readyRecipes[101], front = 0, back = 0;
        vector<string> ans;
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
                readyRecipes[back++] = i;

        while (front != back) {
            int i = readyRecipes[front++];
            auto s = recipes[i];
            ans.push_back(s);
            for (auto j : adj[s]) {
                if (--inDegree[j] == 0)
                    readyRecipes[back++] = j;
            }
        }
        return ans;
    }
};
/*
    supplies[] = "yeast", "flour", "meat"
    sandwich -> burger
    bread -> burger
    bread -> sandwich
*/