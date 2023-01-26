class Solution
{
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
		vector<pair<int, int>> graphAdj[n];
		queue<pair<int, pair<int, int>>> q;
		vector<int> updateDist(n, INT_MAX);
		for (auto it : flights)
		{
			graphAdj[it[0]].push_back({ it[1], it[2] });
		}
		q.push({ 0, {src, 0} });
		updateDist[src] = 0;
		while (!q.empty())
		{
			auto it = q.front();
			q.pop();
			int stops = it.first, node = it.second.first, cost = it.second.second;
			if (stops > K)
				continue;
			for (auto it : graphAdj[node])
			{
				if (cost + it.second < updateDist[it.first] && stops <= K)
				{
					updateDist[it.first] = cost + it.second;
					q.push({ stops + 1, {it.first, cost + it.second} });
				}
			}
		}
		if (updateDist[dst] == INT_MAX)
			return -1;
		return updateDist[dst];
	}
};