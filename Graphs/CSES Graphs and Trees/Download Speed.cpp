    #include <bits/stdc++.h>
    typedef long long ll;
    #define fo(i, n) for(ll i=0;i<n;i++)
    #define vi vector<ll>
    #define vp vector< pair <ll,ll> >
    #define f first
    #define s second
    #define pb push_back
    #define endl '\n'

    using namespace std;

    long long max_flow(vector<vector<int>> adj, vector<vector<long long>> capacity, int source, int sink) {
        int n = adj.size();
        vector<int> parent(n, -1);

        // Find a way from the source to sink on a path with non-negative capacities
        auto reachable = [&]() -> bool {
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto son : adj[node]) {
                    long long w = capacity[node][son];
                    if (w <= 0 || parent[son] != -1) continue;
                    parent[son] = node;
                    q.push(son);
                }
            }
            return parent[sink] != -1;
        };

        long long flow = 0;

        // While there is a way from source to sink with non-negative capacities
        while (reachable()) {
            int node = sink;

            // The minimum capacity on the path from source to sink
            long long curr_flow = LLONG_MAX;
            while (node != source) {
                curr_flow = min(curr_flow, capacity[parent[node]][node]);
                node = parent[node];
            }
            node = sink;
            while (node != source) {
                // Subtract the capacity from capacity edges
                capacity[parent[node]][node] -= curr_flow;
                // Add the current flow to flow backedges
                capacity[node][parent[node]] += curr_flow;
                node = parent[node];
            }
            flow += curr_flow;
            fill(parent.begin(), parent.end(), -1);
        }

        return flow;
    }


    void solve()
    {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> capacity(n, vector<long long>(n, 0));
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            --a;
            --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            capacity[a][b] += c;
        }

        cout << max_flow(adj, capacity, 0, n - 1) << endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }