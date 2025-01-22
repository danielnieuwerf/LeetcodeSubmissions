class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n;
        int best = 0;
        while(low<=high) {
            int mid = (low+high)/2;
            int citationsAtLeastMid = 0;
            for(int count: citations)
                if(count >= mid)
                    citationsAtLeastMid++;
            if(citationsAtLeastMid >= mid) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return best;
    }
};