class Solution {
public:
	void dfs(int vertex, vector<int> tree[], string &labels, vector<int> &vis, vector<int> &results, map<char, int> &mp)
	{
		vis[vertex] = 1;
		int cnt = mp[labels[vertex]];
		mp[labels[vertex]]++;
		for (auto child : tree[vertex]) {
			if (vis[child] == 0) {
				dfs(child, tree, labels, vis, results, mp);
			}
		}
		//cout << vertex << "   " << cnt << endl;
		results[vertex] = mp[labels[vertex]] - cnt;
	}
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
	{
		vector<int>vis(n, 0), tree[n];
		for (int i = 0; i < edges.size(); i++)
		{
			tree[edges[i][0]].push_back(edges[i][1]);
			tree[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int> results(n);
		map<char, int>mp;
		dfs(0, tree, labels, vis, results, mp);
		return results;
	}
};