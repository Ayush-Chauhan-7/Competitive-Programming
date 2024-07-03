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
    vi adj[mxN], height(mxN);
    ll ans = 0;

    void dfs(ll u=0, ll p=-1)
    {
        for(auto v: adj[u])
        {
            if(v!=p)
            {
                dfs(v,u);
                ans = max(ans, height[u]+height[v]+1);
                height[u] = max(height[u],height[v]+1);
            }
        }
    }

    void solve()
    {
        ll n,u,v;
        cin>>n;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
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