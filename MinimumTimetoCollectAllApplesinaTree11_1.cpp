class Solution {
public:
	int dfs(int vertex, vector<int> tree[], vector<bool>& hasApple, vector<int>&vis)
	{
		vis[vertex] = 1;
		int minTime = 0;
		for (auto it : tree[vertex])
		{
			if (!vis[it])
				minTime += dfs(it, tree, hasApple, vis);
		}
		if (minTime > 0 && vertex != 0) minTime += 2;
		if (minTime == 0 && hasApple[vertex] == true && vertex != 0)minTime += 2;
		return minTime;
	}
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		vector<int>vis(n, 0);
		vector<int> tree[n];
		for (int i = 0; i < edges.size(); i++)
		{
			tree[edges[i][0]].push_back(edges[i][1]);
			tree[edges[i][1]].push_back(edges[i][0]);
		}
		return dfs(0, tree, hasApple, vis);
	}
};