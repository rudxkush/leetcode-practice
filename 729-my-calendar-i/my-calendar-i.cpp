#include <map>
using namespace std;

class MyCalendar {
    map<int, int> mp; // start -> end
public:
    MyCalendar() {}

    bool book(int startTime, int endTime) {
        auto next = mp.lower_bound(startTime);
        
        if(next != mp.end() && next->first < endTime) return false;

        if(next != mp.begin()) {
            auto prev_it = prev(next);
            if(prev_it->second > startTime) return false;
        }

        // No overlaps
        mp[startTime] = endTime;
        return true;
    }
};
