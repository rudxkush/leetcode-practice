class MyCalendar {
    set<pair<int, int>> st;

public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (const auto& interval : st) {
            if (max(interval.first, startTime) < min(interval.second, endTime)) {
                return false;
            }
        }
        st.insert({startTime, endTime});
        return true;
    }
};
