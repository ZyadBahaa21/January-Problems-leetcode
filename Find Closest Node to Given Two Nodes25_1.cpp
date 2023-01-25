class Solution {
public:
	void dfs(int vertex, int dist, vector<int> &edges, vector<int>& distance) {
		while (vertex != -1 && distance[vertex] == -1) {
			distance[vertex] = dist++;
			vertex = edges[vertex];
		}
	}
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		int res = -1, min_dist = INT_MAX, n = edges.size();
		vector<int> distanceF(n, -1), distanceS(n, -1);
		dfs(node1, 0, edges, distanceF);
		dfs(node2, 0, edges, distanceS);
		for (int i = 0; i < n; ++i) {
			if (min(distanceF[i], distanceS[i]) >= 0 && max(distanceF[i], distanceS[i]) < min_dist) {
				min_dist = max(distanceF[i], distanceS[i]);
				res = i;
			}
		}
		return res;
	}
};