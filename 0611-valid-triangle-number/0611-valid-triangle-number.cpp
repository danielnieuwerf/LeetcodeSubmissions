struct Triangle {
    int x;
    int y;
    int z;
     
    bool operator==(const Triangle& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

inline bool operator<(const Triangle& a, const Triangle& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        std::sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                int k = j+1;
                while (k < n) {
                    if (nums[i] + nums[j] > nums[k]) {
                        ++ans;
                        ++k;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
