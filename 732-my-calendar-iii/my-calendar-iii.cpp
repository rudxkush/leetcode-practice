class MyCalendarThree {
    map<int, int> timeline;
    int maxOverlap = 0;

public:
    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        timeline[startTime]++; 
        timeline[endTime]--;  

        int active = 0;
        for (auto& [time, count] : timeline) {
            active += count;
            maxOverlap = max(maxOverlap, active);
        }

        return maxOverlap;
    }
};
