class Solution {
public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		string storeMini, result = "";
		char from, to;
		for (char i = 'a'; i <= 'z'; i++)storeMini.push_back(i);
		for (int i = 0; i < s2.size(); i++)
		{
			from = max(storeMini[s1[i] - 'a'], storeMini[s2[i] - 'a']);
			to = min(storeMini[s1[i] - 'a'], storeMini[s2[i] - 'a']);
			for (auto &it : storeMini)
			{
				if (it == from)it = to;
			}
		}
		for (auto it : baseStr)
			result.push_back(storeMini[it - 'a']);
		return result;
	}
};