class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m; 
        vector<int> left(n1);
        vector<int> right(n2);
        for(int i = 0; i < n1; i++) {
            left[i] = nums[l + i];
        }
        for(int i = 0; i < n2; i++) {
            right[i] = nums[m + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while(i < n1) {
            nums[k++] = left[i++]; 
        }

        while(j < n2) {
            nums[k++] = right[j++]; 
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        // base case
        if(l >= r) return ;

        int m = (l + r) >> 1;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        // merge the partitions
        merge(nums, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        // Merge sort
        // Time Complexity : O(n * logn)
        // Space Complexity : O(n + logn), log n -> recursion stack
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};