class FrontMiddleBackQueue {
    deque<int> vals;

public:
    FrontMiddleBackQueue() {
    }

    void pushFront(int val) {
        vals.push_front(val);
    }

    void pushMiddle(int val) {
        auto it = vals.begin() + vals.size() / 2;
        vals.insert(it, val);
    }

    void pushBack(int val) {
        vals.push_back(val);
    }

    int popFront() {
        if (vals.empty()) {
            return -1;
        }

        int val = vals.front();
        vals.pop_front();
        return val;
    }

    int popMiddle() {
        if (vals.empty()) {
            return -1;
        }

        auto it = vals.begin() + (vals.size() - 1) / 2;
        int val = *it;
        vals.erase(it);
        return val;
    }

    int popBack() {
        if (vals.empty()) {
            return -1;
        }

        int val = vals.back();
        vals.pop_back();
        return val;
    }
};