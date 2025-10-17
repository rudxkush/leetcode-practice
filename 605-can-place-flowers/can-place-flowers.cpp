class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int size = fb.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (fb[i] == 0) {
                bool leftEmpty = (i == 0) || (fb[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (fb[i + 1] == 0);
                if (leftEmpty && rightEmpty) {
                    fb[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};
