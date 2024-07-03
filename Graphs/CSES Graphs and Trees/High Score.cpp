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

    void dfs(int u, vector<vi> &adj, vi& vis)
    {
        vis[u] = 1;
        for(auto v:adj[u])
            if(!vis[v])
                dfs(v,adj,vis);
    }

    void solve()
    {
        ll n,m,u,v,w;
        cin>>n>>m;
        vector<vi> adj(n), adjR(n), edges;
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            edges.pb({u,v,w});
            adj[u].pb(v);
            adjR[v].pb(u);
        }
        vi vis(n),visR(n), dist(n,-1e18);
        dist[0] = 0;
        dfs(0,adj,vis);
        dfs(n-1,adjR,visR);
        fo(i,n)
        {
            for(auto x:edges)
            {
                if(dist[x[0]]!=-1e18 && dist[x[1]]<dist[x[0]]+x[2])
                {
                    dist[x[1]]=dist[x[0]]+x[2];
                    if(i==n-1 && vis[x[1]] && visR[x[1]])
                    {
                        cout<<-1<<endl;
                        return;
                    }
                }
            }
        }
        cout<<dist[n-1]<<endl;
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