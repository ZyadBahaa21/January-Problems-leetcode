class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		map<int, int>mp;
		int ans = -1;
		for (int i = 0; i < trust.size(); i++)
		{
			mp[trust[i][1]]++;
			mp[trust[i][0]]--;
		}
		for (auto it : mp) {
			if (it.second == n - 1)
			{
				ans = it.first; break;
			}
		}
		if (trust.size() == 0 && n == 1)
			return 1;
		else return ans;
	}
};