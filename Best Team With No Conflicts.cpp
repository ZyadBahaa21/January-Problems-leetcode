class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int ans = 0;
		vector<int>textMaxi(1000005);
		vector<pair<int, int>>vp;
		for (int i = 0; i < scores.size(); i++)
			vp.push_back(make_pair(ages[i], scores[i]));
		sort(vp.begin(), vp.end());
		for (int i = 0; i < scores.size(); i++) {
			textMaxi[i] = vp[i].second;
			for (int j = 0; j < i; j++) {
				if (vp[j].second <= vp[i].second)
					textMaxi[i] = max(textMaxi[i], textMaxi[j] + vp[i].second);
			}
			ans = max(ans, textMaxi[i]);
		}
		return ans;
	}
};