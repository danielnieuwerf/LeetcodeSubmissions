class MyCalendarTwo {
    map<int,int> bookings;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        int overlappingBookings = 0;
        ++bookings[start];
        --bookings[end];
        for(auto& p: bookings) {
            overlappingBookings += p.second;
            if (overlappingBookings >= 3) {
                --bookings[start];
                ++bookings[end];                
                if (bookings[start] == 0) {bookings.erase(start);}
                if (bookings[end] == 0) {bookings.erase(end);}
                return false;
            }

            if(p.first > end){
                break;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */