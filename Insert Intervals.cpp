class Solution {
	public
		vectorvectorint insert(vectorvectorint& intervals, vectorint& newInterval) {
		vectorvectorint result;
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());
		int cnt = 0;
		for (int i = 1, strt = 0, end = 1; i intervals.size(); i++) {
			if (intervals[cnt][end] = intervals[i][strt]) {
				intervals[cnt][strt] = min(intervals[cnt][strt], intervals[i][strt]);
				intervals[cnt][end] = max(intervals[cnt][end], intervals[i][end]);
			}
			else {
				cnt++;
				intervals[cnt] = intervals[i];
			}
			cout  intervals[cnt][0]    intervals[cnt][1]  endl;
		}
		for (int i = 0; i = cnt; i++) {
			result.push_back(intervals[i]);
		}
		return result;
	}
};