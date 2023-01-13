class Solution {
public:
	int dfs(int vertex, vector<vector<int>>& adj, string& s, int& result) {
		int First = 0, Second = 0;
		for (auto child : adj[vertex])
		{
			int longest = dfs(child, adj, s, result);
			if (s[vertex] == s[child])
				continue;
			if (longest > First) {
				Second = First;
				First = longest;
			}
			else if (longest > Second)
				Second = longest;
		}
		result = max(result, First + Second + 1);// maximize 
		return First + 1;
	}
	int longestPath(vector<int>& parent, string s) {
		vector<vector<int>> adj(parent.size());
		for (int i = 1; i < parent.size(); i++)
			adj[parent[i]].push_back(i);
		int result = 1;
		dfs(0, adj, s, result);
		return result;
	}
};