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

    void dijkstra(int src, vector<vp> &adj, vi &dist)
    {
        dist[src] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0,src});
        while(!q.empty())
        {
            auto [dis,u] = q.top();
            q.pop();
            if(dis!=dist[u])
                continue;
            for(auto [v,w]:adj[u])
            {
                if(dis+w<dist[v])
                {
                    dist[v] = dis+w;
                    q.push({dist[v],v});
                }
            }
        }
    }

    void solve()
    {
        ll n,m,u,v,w,ans=1e18;
        cin>>n>>m;
        vector<vp> adj(n),adjR(n);
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
            adjR[v].pb({u,w});
        }
        vi dist(n,1e18),distR(n,1e18);
        dijkstra(0,adj,dist);
        dijkstra(n-1,adjR,distR);
        fo(u,n)
        {
            for(auto [v,w]: adj[u])
                ans = min(ans, dist[u] + distR[v] + w/2);
        }
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