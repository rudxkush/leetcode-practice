class MyCalendarTwo {
    map<int, int> events;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Add +1 at start, -1 at end
        events[start]++;
        events[end]--;

        int active = 0;
        for (auto [time, count] : events) {
            active += count;
            if (active >= 3) {
                // Triple booking detected — rollback and return false
                events[start]--;
                events[end]++;
                if (events[start] == 0) events.erase(start);
                if (events[end] == 0) events.erase(end);
                return false;
            }
        }
        return true;
    }
};
