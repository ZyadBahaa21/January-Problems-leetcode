class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int cnt = 0, bola = 0, len = strs[0].size();
		for (int i = 0; i < len; i++)
		{
			bola = 1;
			for (int j = 0; j < strs.size() - 1; j++)
			{
				if (strs[j][i] > strs[j + 1][i])bola = 0;
			}
			if (bola)cnt++;
		}
		return len - cnt;
	}
};