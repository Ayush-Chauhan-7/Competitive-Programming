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
        vector<vi> adj(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
        }
        vi vis(n),p(n);
        auto dfs = [&](int u, auto&& dfs)->void
        {
            vis[u] = 2;
            for(auto v:adj[u])
            {
                if(!vis[v])
                {
                    p[v] = u;
                    dfs(v,dfs);
                }
                else if(vis[v]==2)
                {
                    vi ans;
                    ans.pb(u);
                    while(u!=v)
                    {
                        u = p[u];
                        ans.pb(u);
                    }
                    ans.pb(ans[0]);
                    reverse(ans.begin(),ans.end());
                    cout<<ans.size()<<endl;
                    for(auto i: ans)
                        cout<<i+1<<" ";
                    exit(0);
                }
            }
            vis[u] = 1;
        };
        fo(i,n)
            if(!vis[i])
                dfs(i,dfs);
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