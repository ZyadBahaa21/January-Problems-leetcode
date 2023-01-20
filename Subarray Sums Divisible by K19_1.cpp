class Solution {
public:
	int subarraysDivByK(vector<int>& nums, int k) {
		int cnt = 0, sum = 0;
		map<int, int>mp;
		mp[0]++;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			cnt += mp[(sum%k + k) % k];
			mp[(sum%k + k) % k]++;
		}
		return cnt;
	}
};