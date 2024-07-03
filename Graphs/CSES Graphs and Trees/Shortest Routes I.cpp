    #include <bits/stdc++.h>
    typedef unsigned long long ll;
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
        ll n,m,u,v,w;
        cin>>n>>m;
        vp adj[n];
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
        }
        vi dist(n,1e19);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty())
        {
            auto [dis, u] = q.top();
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
        fo(i,n)
            cout<<dist[i]<<" ";
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