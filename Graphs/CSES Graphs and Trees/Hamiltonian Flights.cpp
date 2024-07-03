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
        ll n,m,u,v,mod = 1e9+7;
        cin>>n>>m;
        vector<vi> adj(n), dp(1 << n, vi(n, 0));
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
        }
        dp[1][0] = 1;
        for (int s = 1; s < 1 << n; s++) {
            if ((s & 1) == 0) continue;
            if ((s & (1 << n - 1)) & (s != (1 << n) - 1)) continue;
            for (int i = 0; i < n; i++) {
                if (s & (1 << i)) {
                    for (auto u : adj[i]) {
                        if (!(s & (1 << u))) {
                            dp[s | (1 << u)][u] += dp[s][i];
                            dp[s | (1 << u)][u] %= mod;
                        }
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1][n - 1];
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