class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = INT_MIN, mini = INT_MAX, sum1 = 0, sum2 = 0, allElement = 0;
        for (auto it : nums) {
            allElement += it;
            sum1 += it;
            maxi = max(maxi, sum1);
            if (sum1 < 0) sum1 = 0;
            sum2 += it;
            mini = min(mini, sum2);
            if (sum2 > 0) sum2 = 0;
        }
        if (maxi < 0)return maxi;
        else return max(allElement - mini, maxi);
    }
};