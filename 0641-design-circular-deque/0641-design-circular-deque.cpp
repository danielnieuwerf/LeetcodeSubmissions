class MyCircularDeque {
    deque<int> _q;
    int _k;
public:
    MyCircularDeque(int k) {
        _k = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) {
            return false;
        }
        _q.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) {
            return false;
        }
        _q.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        _q.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        _q.pop_back();
        return true;
    }
    
    int getFront() {
        if(isEmpty()) 
            return -1;
        return _q.front();
    }
    
    int getRear() {
        if(isEmpty()) 
            return -1;
        return _q.back();
    }
    
    bool isEmpty() {
        return _q.empty();
    }
    
    bool isFull() {
        return _q.size() == _k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */