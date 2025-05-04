class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        // copy contents
        for (int i = 0; i < n1; i++) {
            leftArr[i] = nums[l + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArr[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k] = leftArr[i];
                i++;
            } else {
                nums[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            nums[k++] = leftArr[i++];
        }
        while (j < n2) {
            nums[k++] = rightArr[j++];
        }
    }
    void countPairs(vector<int>& nums, int l, int mid, int r, int& count) {
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * (long long)nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
    }
    void mergeSort(vector<int>& nums, int l, int r, int& count) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid, count);
        mergeSort(nums, mid + 1, r, count);
        countPairs(nums, l, mid, r, count);
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergeSort(nums, 0, n - 1, count);
        return count;
    }
};