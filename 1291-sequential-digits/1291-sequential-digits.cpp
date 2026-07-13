class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        auto seqs = vector<vector<int>>{getTwoDigitSequentials(), getThreeDigitSequentials(), getFourDigitSequentials(), getFiveDigitSequentials(), getSixDigitSequentials(), getSevenDigitSequentials(),  getEightDigitSequentials(), getNineDigitSequentials()};
        for(auto seq: seqs) {
            for(auto val: seq) {
                if(val > high)
                    break;
                if(val>= low && val <= high)
                    ans.push_back(val);
            }
        }
        return ans;
    }

    constexpr vector<int> getTwoDigitSequentials() {
        return {12, 23, 34, 45, 56, 67, 78, 89};
    }

    constexpr vector<int> getThreeDigitSequentials() {
        return {123, 234, 345, 456, 567, 678, 789 };
    }

    constexpr vector<int> getFourDigitSequentials() {
        return {1234, 2345, 3456, 4567, 5678, 6789 };
    }

    constexpr vector<int> getFiveDigitSequentials() {
        return {12345, 23456, 34567, 45678, 56789 };
    }

    constexpr vector<int> getSixDigitSequentials() {
        return {123456, 234567, 345678, 456789 };
    }

    constexpr vector<int> getSevenDigitSequentials() {
        return {1234567, 2345678, 3456789 };
    }

    constexpr vector<int> getEightDigitSequentials() {
        return {12345678, 23456789 };
    }

    constexpr vector<int> getNineDigitSequentials() {
        return {123456789 };
    }
};