    // https://codeforces.com/contest/1092/problem/F
    
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
    ll n,u,v,res=0,ans=0;
    vi adj[mxN], a(mxN), d(mxN), sz(mxN);

    void dfs(ll u=0, ll p=-1)
    {
        sz[u] = a[u];
        res += (d[u]*a[u]);
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            d[v] = d[u] + 1;
            dfs(v,u);
            sz[u] += sz[v];
        }
    }

    void dfs2(ll u=0, ll p=-1)
    {
        ans = max(ans,res);
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            res += (sz[0] - 2*sz[v]);
            dfs2(v,u);
            res -= (sz[0] - 2*sz[v]);
        }

    }

    void solve()
    {
        cin>>n;
        fo(i,n)
            cin>>a[i];
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