class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> prefix(n + 2, 0);
        for(int i = 0; i < bookings.size(); i++) {
            int left = bookings[i][0]; 
            int right = bookings[i][1]; 
            int seatsReserved = bookings[i][2]; 
            prefix[left] += seatsReserved;
            prefix[right + 1] -= seatsReserved;
        }      
        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }
        return  vector<int>(prefix.begin() + 1, prefix.begin() + n + 1);
    }
};