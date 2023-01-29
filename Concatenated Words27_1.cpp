class Solution {
public:
	bool divide(string s, set<string>&dictionary) {
		for (int i = 1; i < s.size(); ++i) {
			string left = s.substr(0, i);
			string right = s.substr(i);
			auto idx = dictionary.find(left);
			auto idx2 = dictionary.find(right);
			if (idx != dictionary.end()) {
				if (idx2 != dictionary.end() || divide(right, dictionary))
					return true;
			}
		}
		return false;
	}
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> result;
		set<string> dictionary;
		for (auto it : words) dictionary.insert(it);
		for (auto it : words)
			if (divide(it, dictionary))
				result.push_back(it);

		return result;
	}
};