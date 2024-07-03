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
        ll n,m,u,v,w,mod = 1e9+7;
        cin>>n>>m;
        vp adj[n];
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
        }
        priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> q;
        vi dist(n,1e18), ways(n), maxi(n), mini(n,1e18);
        dist[0] = 0;
        maxi[0] = mini[0] = 0;
        ways[0] = 1;
        q.push({0,0});
        while(q.size())
        {
            auto x = q.top();
            q.pop();
            ll dis = x[0];
            ll u = x[1];
            if(dis!=dist[u])
                continue;
            for(auto [v,w] : adj[u])
            {
                ll newDis = dis + w;
                if(newDis < dist[v])
                {
                    dist[v] = newDis;
                    ways[v] = ways[u];
                    mini[v] = mini[u]+1;
                    maxi[v] = maxi[u]+1;
                    q.push({newDis,v});
                }
                else if(newDis == dist[v])
                {
                    ways[v] = (ways[v]+ways[u])%mod;
                    mini[v] = min(mini[v],mini[u]+1);
                    maxi[v] = max(maxi[v],maxi[u]+1);
                }
            }
        }
        cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<mini[n-1]<<" "<<maxi[n-1]<<endl;
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