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
    vi adj[mxN], h(mxN), sz(mxN), ans(mxN);
    ll n;

    void dfs(ll u=0, ll p=-1)
    {
        sz[u] = 1;
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            h[v] = 1 + h[u];
            dfs(v,u);
            sz[u] += sz[v];
        }
    }

    void dfs2(ll u=0, ll p=-1)
    {
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            ans[v] = ans[u] - sz[v] + (n-sz[v]);
            dfs2(v,u);
        }
    }

    void solve()
    {
        ll u,v;
        cin>>n;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        fo(i,n)
            ans[0] += h[i];
        dfs2();
        fo(i,n)
            cout<<ans[i]<<" ";
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