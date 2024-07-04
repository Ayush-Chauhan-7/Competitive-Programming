    // https://codeforces.com/contest/1187/problem/E
    
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

    const int mxN = 2e5;
    vi adj[mxN];
    ll n,u,v,dp[mxN],res=0,ans=0;

    void dfs(ll u=0, ll p=-1)
    {
        dp[u] = 1;
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            dfs(v,u);
            dp[u] += dp[v];
        }
        res += dp[u];
    }

    void dfs2(ll u=0, ll p=-1)
    {
        ans = max(ans,res);
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            res += (n - (2*dp[v]));
            dfs2(v,u);
            res -= (n - (2*dp[v]));
        }
    }

    void solve()
    {
        cin>>n;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        dfs2();
        cout<<ans<<endl;
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