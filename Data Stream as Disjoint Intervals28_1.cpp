class SummaryRanges {
public:
	set<int> st;
	SummaryRanges() {
	}
	void addNum(int value) {
		st.insert(value);
	}
	vector<vector<int>> getIntervals() {
		vector<vector<int>> ans;
		int start = -1, end = -1;
		for (auto it : st) {
			if (start < 0)
			{
				start = it;
				end = it;
			}
			else if (it == end + 1)
				end = it;
			else
			{
				ans.push_back({ start,end });
				start = end = it;
			}
		}
		ans.push_back({ start,end });
		return ans;
	}
};



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */