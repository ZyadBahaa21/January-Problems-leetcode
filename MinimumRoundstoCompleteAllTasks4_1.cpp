class Solution {
public:
	int minimumRounds(vector<int>& tasks) {
		vector<int> v = tasks;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		map<int, int>mp;
		int cnt = 0;
		for (auto it : tasks)mp[it]++;
		for (auto it : v)
		{
			if (mp[it] == 1)return -1;
			if (mp[it] % 3 == 0)cnt += (mp[it] / 3);
			else cnt += (mp[it] / 3) + 1;
		}
		return cnt;
	}
};