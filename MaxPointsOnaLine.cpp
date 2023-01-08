class Solution {
public:
	int maxPoints(vector<vector<int>>& v) {
		int maxi = 0, maxi2 = 0;
		float slope;
		map<float, int>mp;
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				// calculate the slope
				slope = (float)(v[j][1] - v[i][1]) / (float)(v[j][0] - v[i][0]);
				if (v[j][0] - v[i][0] == 0 && v[j][1] - v[i][1] < 0)mp[abs(slope)]++;
				else mp[slope]++;
			}
			// get the max number of points that have same slope 
			for (auto it : mp) maxi = max(maxi, it.second);
			// maximize because you try each point with others
			maxi2 = max(maxi2, maxi);
			maxi = 0;
			mp.clear();
		}
		return maxi2 + 1;


	}
};