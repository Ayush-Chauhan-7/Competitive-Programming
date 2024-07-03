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
        ll n,m,u,v;
        cin>>n>>m;
        vi adj[n], vis(n), pr(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        auto dfs = [&adj, &vis, &pr](int u, int p, auto&& dfs) -> void
        {
            pr[u] = p;
            vis[u] = 1;
            for(auto v:adj[u])
            {
                if(v==p)
                    continue;
                if(vis[v])
                {
                    ll x = u;
                    vi cycle;
                    while(x!=v)
                    {
                        cycle.pb(x+1);
                        x = pr[x];
                    }
                    cycle.pb(v+1);
                    cycle.pb(u+1);
                    cout<<cycle.size()<<endl;
                    for(auto i:cycle)
                        cout<<i<<" ";
                    exit(0);
                }
                else
                    dfs(v,u,dfs);
            }
        };
        fo(i,n)
            if(!vis[i])
                dfs(i,-1,dfs);
        cout<<"IMPOSSIBLE"<<endl;
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