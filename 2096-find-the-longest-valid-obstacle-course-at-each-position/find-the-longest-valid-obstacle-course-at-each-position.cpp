class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> courses; // the longest course
        for(int& height : obstacles) {
            if(courses.empty() || courses.back() <= height) {
                // if the course is empty or the current obstacle is higher than the last obstacle in the course, append it to the longest course
                courses.push_back(height);
                height = courses.size();
            } else {
                // find the first obstacle's height that is higher than current obstacle and replace it with the current height
                // the longest course will remain valid as we maintain the maximum height of "each course" to the lowest value
                // [1, 2, 3] ==>> [1, 2, 2] after replacing the "3" with "2"
                auto it = upper_bound(courses.begin(), courses.end(), height);
                *it = height;
                height = distance(courses.begin(), it) + 1;
            }
        }
        return obstacles;
    }
};
/*
array : [3,1,5,6,4,2]
temp : [1e9, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : []

index 0 :
upper_bound of 3 is at index 0
store 3 at index 0
temp : [3, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : [1]

index 1 :
upper_bound of 1 is at index 0
store 1 at index 0
temp : [1, 1e9, 1e9, 1e9, 1e9, 1e9]
ans : [1, 1]

index 2 :
upper_bound of 5 is at index 1
store 5 at index 1
temp : [1, 5, 1e9, 1e9, 1e9, 1e9]
ans : [1, 1, 2]

index 3 :
upper_bound of 6 is at index 2
store 6 at index 2
temp : [1, 5, 6, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3]

index 4 :
upper_bound of 4 is at index 1
store 4 at index 1
temp : [1, 4, 6, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3, 2]

index 5 :
upper_bound of 2 is at index 1
store 2 at index 1
temp : [1, 2, 2, 1e9, 1e9, 1e9]
ans : [1, 1, 2, 3, 2, 2]
*/