class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b){
            if (abs(a - x) == abs(b - x)) {
                return a < b;
            }
            return abs(a - x) < abs(b - x);
        });

        vector<int> result(arr.begin(), arr.begin() + k);

        sort(result.begin(), result.end());

        return result;
    }
};