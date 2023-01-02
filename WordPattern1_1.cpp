class Solution {
public:
	bool wordPattern(string p, string s) {
		int idxP = 0;
		s += " ";
		string str = "";
		set<char>chr;
		set<string>strs;
		map<char, string> mp;
		for (auto ch : p) chr.insert(ch);
		for (int i = 0; i < s.length(); i++) {
			if (idxP == p.length()) return false;

			if (s[i] == ' ') {
				if (mp.find(p[idxP]) == mp.end())
					mp[p[idxP]] = str;
				else if (mp[p[idxP]] != str)
					return false;
				strs.insert(str);
				str.clear();
				idxP++;
			}
			else
				str.push_back(s[i]);
		}
		return (chr.size()) == (strs.size());
	}
};