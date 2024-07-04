    // https://codeforces.com/contest/1882/problem/D
    
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


    void solve()
    {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> siz(n);
        vector<ll> add(n);
        ll ans = 0;
        auto dfs1 = [&](auto self, int x, int p) -> void {
            siz[x] = 1;
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                self(self, y, x);
                siz[x] += siz[y];
                ans += 1LL * siz[y] * (a[x] ^ a[y]);
                add[y] += 1LL * (n - siz[y] * 2) * (a[x] ^ a[y]);
            }
        };
        dfs1(dfs1, 0, -1);
        
        auto dfs2 = [&](auto self, int x, int p) -> void {
            for (auto y : adj[x]) {
                if (y == p) {
                    continue;
                }
                add[y] += add[x];
                self(self, y, x);
            }
        };
        dfs2(dfs2, 0, -1);
        
        for (int i = 0; i < n; i++) {
            cout << ans + add[i] << " \n"[i == n - 1];
        }
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }