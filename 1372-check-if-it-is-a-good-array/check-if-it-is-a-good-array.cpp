class Solution {
public:
    int greatestCommonDiv(int a, int b) {
        while(b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    bool isGoodArray(vector<int>& nums) {
        int n = (int) nums.size();
        if(n == 1) {
            return nums[0] == 1;
        }
        int G = nums[0];
        for(int i = 1; i < n; i++) {
            G = greatestCommonDiv(nums[i], G);
            // for(int j = i + 1; j < n; j++) {
            //     G = greatestCommonDiv(G, nums[j]);
            // }
            if(G == 1) {
                return true;
            }
        }
        return false;
    }
};

// 12, 5, 7, 23

// subset picked -> [5, 7]
// (5x + 7y) = 1
// x, y would vary and also the number of varibles