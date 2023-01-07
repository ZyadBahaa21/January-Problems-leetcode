class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int idx = 0, now = 0;
		for (int i = 0; i < cost.size(); i++)
		{
			now += gas[i] - cost[i];
			if (now < 0)
			{
				now = 0;
				idx = i + 1;
			}
		}
		for (int i = 0; i < idx; i++) {
			now += gas[i] - cost[i];
			if (now < 0)
			{
				return -1;
			}
		}
		return idx;
	}
};