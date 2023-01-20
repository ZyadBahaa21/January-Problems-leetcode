class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		set<vector<int>>store;
		vector<int>temp;
		vector<vector<int>>ans;
		for (int i = 0; i < (1 << nums.size()); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i&(1 << j))
					temp.push_back(nums[j]);
			}
			if (temp.size() > 1)
			{
				if (is_sorted(temp.begin(), temp.end()))
					store.insert(temp);
			}
			temp.clear();
		}
		while (!store.empty())
		{
			ans.push_back(*store.begin());
			store.erase(store.begin());
		}
		return ans;
	}
};