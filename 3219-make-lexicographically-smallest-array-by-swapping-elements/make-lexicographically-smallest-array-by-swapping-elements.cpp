class DisjointSet {
    vector<int> parent, size;

public:
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // path compression
    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if (ultimateParent_u == ultimateParent_v)
            return;

        if (size[ultimateParent_u] < size[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        } else {
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // 2nlogn + 3n
        int n = nums.size();
        DisjointSet ds(n);
        vector<pair<int, int>> valWithIndex;
        for (int i = 0; i < n; i++) {
            valWithIndex.push_back({nums[i], i}); // (value, index)
        }

        sort(valWithIndex.begin(), valWithIndex.end()); // sorts by value

        for (int i = 1; i < n; i++) {
            int val1 = valWithIndex[i - 1].first;
            int val2 = valWithIndex[i].first;
            int idx1 = valWithIndex[i - 1].second;
            int idx2 = valWithIndex[i].second;

            if (abs(val1 - val2) <= limit) {
                ds.unionBySize(idx1, idx2);
            }
        }
        // 1. Group indices by their DSU parent
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            int parent = ds.findUltimateParent(i);
            components[parent].push_back(i);
            // collect all indices in the same component
        }

        // 2. Sort each group’s indices and values, then assign
        vector<int> result = nums;
        for (auto [parent, indices] : components) {
            vector<int> values;

            for (int idx : indices) {
                values.push_back(nums[idx]);
            }

            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = values[i];
            }
        }
        return result;
    }
};

//     int n = nums.size();

//     for (int i = 0; i < n; i++) {
//         int currEle = nums[i];
//         while (true) {
//             int idx = -1;
//             for (int j = i + 1; j < n; j++) {
//                 if (abs(nums[i] - nums[j]) <= limit) {
//                     if (currEle > nums[j]) {
//                         swap(nums[i], nums[j]);
//                         idx = j;
//                     }
//                 }
//             }
//             if(idx == -1) {
//                 break;
//             }
//         }
//     }
//     return nums;
// }