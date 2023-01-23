class Solution {
public:
	vector<vector<string>> result;
	bool checkPalind(string p) {
		int n = p.length();
		for (int i = 0; i < n / 2; i++) {
			if (p[i] != p[n - i - 1]) {
				return false;
			}
		}
		return true;
	}
	void devide(string s, int idx, vector<string> v) {
		if (idx == s.length())
		{
			result.push_back(v);
			return;
		}
		int i = idx;
		while (i < s.length()) {
			if (checkPalind(s.substr(idx, i - idx + 1))) {
				v.push_back(s.substr(idx, i - idx + 1));
				devide(s, i + 1, v);
				v.pop_back();
			}
			i++;
		}
	}
	vector<vector<string>> partition(string s) {
		vector<string> v;
		devide(s, 0, v);
		return result;
	}
};