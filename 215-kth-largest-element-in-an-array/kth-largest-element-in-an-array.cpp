class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int, vector<int>, greater<int> > pQ;

       for(int i = 0; i < nums.size(); i++) {
        pQ.push(nums[i]);
        if(pQ.size() > k) {
            pQ.pop();
        }
       }
       return pQ.top();
    }
};