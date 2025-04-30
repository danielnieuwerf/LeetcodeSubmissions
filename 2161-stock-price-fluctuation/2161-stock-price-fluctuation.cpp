class StockPrice {
    map<int, int> stock; 
    map<int, int> prices;
    pair<int,int> currentPrice = {-1, -1};
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timestamp >= currentPrice.first) {
            currentPrice = {timestamp, price};
        }
        if(stock.find(timestamp) != stock.end()) {
            auto count = --prices[stock[timestamp]];
            if(count == 0) {
                prices.erase(stock[timestamp]);
            }
        }
        prices[price]++;
        stock[timestamp] = price;
    }
    
    int current() {
        return currentPrice.second;
    }
    
    int maximum() {
        return prices.rbegin()->first;
    }
    
    int minimum() {
        return prices.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */