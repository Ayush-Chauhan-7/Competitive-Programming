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
        vi adj[n],vis(n),ans;
        fo(i,m)
        {
            cin>>u>>v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        auto dfs = [&adj, &vis](int u, auto&& dfs) -> void
        {
            vis[u] = 1;
            for(auto v:adj[u])
                if(!vis[v])
                    dfs(v,dfs);
        };

        fo(i,n)
            if(!vis[i])
                dfs(i,dfs),ans.pb(i+1);
        ll c = ans.size();
        cout<<c-1<<endl;
        fo(i,c-1)
            cout<<ans[i]<<" "<<ans[c-1]<<endl;
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