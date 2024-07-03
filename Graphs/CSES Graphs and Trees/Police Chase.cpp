#include <bits/stdc++.h>
using namespace std;
 
const int $S = 1e4, INF = 1e9;
 
int main() {
	int N, M;
	cin >> N >> M;
 
	int S = 0;
	static array<int, $S> F, C;
	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		
		C[S] = 1, F[S] = 0;
		G[u].emplace_back(v, S++);
		C[S] = 0, F[S] = 0;
		G[v].emplace_back(u, S++);
 
		C[S] = 0, F[S] = 0;
		G[u].emplace_back(v, S++);
		C[S] = 1, F[S] = 0;
		G[v].emplace_back(u, S++);
	}
 
	queue<int> que;
	long long ans = 0;
	vector<int> mnr(N), par(N), pid(N);
	while (true) {
		fill(par.begin(), par.end(), -1);
		que.push(0);
		par[0] = 0, mnr[0] = INF;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (auto [v, k] : G[u]) {
				if (par[v] == -1 && C[k] != F[k]) {
					mnr[v] = min(mnr[u], C[k] - F[k]);
					par[v] = u;
					pid[v] = k;
					que.push(v);
				}
			}
		}
		if (par[N - 1] == -1)
			break;
		ans += mnr[N - 1];
		for (int u = N - 1; u != 0; u = par[u]) {
			F[pid[u]] += mnr[N - 1];
			F[pid[u] ^ 1] -= mnr[N - 1];
		}
	}
 
	fill(par.begin(), par.end(), -1);
 
	que.push(0);
	par[0] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto [v, k] : G[u]) {
			if (par[v] == -1 && C[k] != F[k]) {
				par[v] = u;
				que.push(v);
			}
		}
	}
 
	cout << ans << '\n';
	for (int u = 0; u < N; u++) {
		for (auto [v, k] : G[u]) 
			if (C[k] == 1 && par[u] != -1 && par[v] == -1) 
				cout << u + 1 << ' ' << v + 1 << '\n';
	}
}