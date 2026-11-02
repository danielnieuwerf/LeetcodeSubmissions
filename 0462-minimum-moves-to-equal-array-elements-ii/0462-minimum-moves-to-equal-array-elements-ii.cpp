class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int median{};
        int count{};
        
        if(n%2==1){
            median=nums[n/2];
        }
        else{
            median=(nums[n/2]+nums[n/2-1])/2;
        }
        for(auto a:nums){
            count+=abs(a-median);
        }
        
        return count;
    }
};