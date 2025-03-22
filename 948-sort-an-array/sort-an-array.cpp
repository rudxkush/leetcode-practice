class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i) {
        int lC = (2*i) + 1;
        int rC = (2*i) + 2;
        int largest = i;

        if(lC < n && nums[lC] > nums[largest]) largest = lC;
        if(rC < n && nums[rC] > nums[largest]) largest = rC;

        if(largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, n, largest);
        }
    }
    void heapSort(vector<int>& nums, int n) {
        for(int i = (n/2)-1; i >= 0; i--) 
            maxHeapify(nums, n , i);

        for(int i = n-1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            maxHeapify(nums, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};