class MyCalendarThree {
    map<int,int> bookings;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++bookings[start];
        --bookings[end];
        int maxOverlap = 1;
        int overlappingBookings = 0;
        for(auto& p: bookings) {
            overlappingBookings += p.second;
            maxOverlap = max(maxOverlap, overlappingBookings);
        }
        return maxOverlap;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */