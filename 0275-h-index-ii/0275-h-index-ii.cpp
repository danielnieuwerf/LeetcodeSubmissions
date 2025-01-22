class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        int best = 0;
        while(low<=high) {
            int mid = (low+high)/2;
            if(citations[mid] == n - mid) {
                return citations[mid];
            } else if(citations[mid] < n - mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return n - low;
    }
};