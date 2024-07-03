#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> in;
vector <vector<int>> out;
vector <vector<int>> back_edge;
long long max_flow(vector<vector<int>> adj, vector<vector<long long>> capacity, int n, int source, int sink) {
	long long flow = 0;
	vector <int> parent(n + 1, -1); 
	auto reachable = [&]() -> bool {
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for(auto son: adj[node]) {
				long long w = capacity[node][son];
				if (w <= 0 || parent[son] != -1) continue;
				parent[son] = node;
				q.push(son);
			}
		}
		return parent[sink] != -1;
	};
	while (reachable()) {
		int node = sink;

		long long curr_flow = LLONG_MAX;
		while (node != source) {
			curr_flow = min(curr_flow, capacity[parent[node]][node]);
			// parent[node] -> node
			
			in[node].push_back(parent[node]);
			out[parent[node]].push_back(node);
			
			node = parent[node];
		}
		node = sink;
		while (node != source) {
			capacity[parent[node]][node] -= curr_flow;
			capacity[node][parent[node]] += curr_flow;
			
			if(back_edge[parent[node]][node] == 1) {
				
				auto it = find(out[node].begin(), out[node].end(), parent[node]);
				assert(it != out[node].end());
				out[node].erase(it);

				it = find(in[parent[node]].begin(), in[parent[node]].end(), node);
				assert(it != in[parent[node]].end());
				in[parent[node]].erase(it);
				


			}
			
			
			node = parent[node];
		}
		flow += curr_flow;
		fill(parent.begin(), parent.end(), -1);
	}
	return flow;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> capacity(n + 1, vector<long long>(n + 1, 0));
	vector<vector<int>> adj(n + 1);

	back_edge.resize(n + 1, vector<int>(n + 1, 0));
	
	in.resize(n + 1);
	out.resize(n + 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if(back_edge[a][b] == 1) {
			back_edge[a][b] = 0;
			back_edge[b][a] = 0;
		}
		else back_edge[b][a] = 1;
		capacity[a][b] += 1;
	}

	cout << max_flow(adj, capacity, n, 1, n) << endl;
	
	vector <vector<int>> vis(n + 1, vector<int>(n + 1, 0));
	vector <vector <int>> ans;

	vector <int> res;

	function<void(int)> dfs;
	dfs = [&](int node) -> void {
		res.push_back(node);
		if(node == 1) return;
		for(int neighbor: in[node]) {
			if(vis[node][neighbor] == 1) continue;
			vis[node][neighbor] = 1;
			dfs(neighbor);
			break;
		}
		return;
	};

	for(auto it: in[n]) { 
		res.clear();
		res.push_back(n);
		if(vis[n][it] == 1) continue;
		vis[n][it] = 1;
		dfs(it);
		reverse(res.begin(), res.end());
		ans.push_back(res);
	}
	for(auto ax: ans) {
		cout << ax.size() << endl;
		for(auto ad: ax) {
			cout << ad << " ";
		}
		cout << endl;
	}
}