class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		sort(points.begin(), points.end());
		int mini = points[0][0], maxi = points[0][1], cnt = 1;
		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] >= mini && points[i][0] <= maxi)
			{

				mini = max(points[i][0], mini);
				maxi = min(points[i][1], maxi);
			}
			else {
				cnt++;
				mini = points[i][0];
				maxi = points[i][1];
			}
		}
		return cnt;
	}
};