class Solution {
public:
    static vector<string> findAllRecipes(vector<string>& recipes,
                                         vector<vector<string>>& ingredients,
                                         vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> s(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>>
            graph; // the idea is here to look in the recipe to determine whose
                   // inDegree we are going to manipulate.
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto ingre : ingredients[i]) {
                if (!s.count(ingre)) {
                    graph[ingre].push_back(i);
                    inDegree[i]++;
                }
            }
        }

        queue<int> q;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int j = q.front();
            q.pop();
            ans.push_back(recipes[j]);

            for (auto nei : graph[recipes[j]]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
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