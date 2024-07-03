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
        ll n,m,u,v,mod=1e9+7;
        cin>>n>>m;
        vector<vi> adj(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
        }
        vi dp(n),vis(n);
        auto dfs = [&](int u, auto&& dfs)->void
        {
            vis[u] = 1;
            if(u==n-1)
            {
                dp[u] = 1;
                return;
            }
            for(auto v: adj[u])
            {
                if(!vis[v])
                    dfs(v,dfs);
                dp[u] = (dp[u]+dp[v])%mod;
            }
        };
        dfs(0,dfs);
        cout<<dp[0]<<endl;
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