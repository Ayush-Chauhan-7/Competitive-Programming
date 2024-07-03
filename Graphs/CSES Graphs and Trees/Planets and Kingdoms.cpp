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

    vi fin, vis, kingdom;
    int scc=1;

    void dfs(ll u, vector<vi> &adj)
    {
        vis[u] = 1;
        kingdom[u] = scc;
        for(auto v : adj[u])
        {
            if(!vis[v])
                dfs(v,adj);
        }
        fin.pb(u);
    }

    void solve()
    {
        ll n,m,u,v;
        cin>>n>>m;
        vector<vi> adj(n), adjR(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adjR[v].pb(u);
        }
        vis.assign(n,0);
        kingdom.resize(n);
        fo(i,n)
            if(!vis[i])
                dfs(i,adj);
        vi x = fin,ans;
        reverse(x.begin(),x.end());
        vis.assign(n,0);
        for(auto i:x)
        {
            if(!vis[i])
            {
                dfs(i,adjR);
                scc++;
            }
        }
        cout<<scc-1<<endl;
        fo(i,n)
            cout<<kingdom[i]<<" ";
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