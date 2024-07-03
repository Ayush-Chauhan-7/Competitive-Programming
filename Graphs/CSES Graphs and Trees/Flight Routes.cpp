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
        ll n,m,k,u,v,w;
        cin>>n>>m>>k;
        vp adj[n];
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            adj[u].pb({v,w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        vi dist[n];
        q.push({0,0});
        while(!q.empty())
        {
            auto [dis, u] = q.top();
            q.pop();
            if(dist[u].size()>=k)
                continue;
            dist[u].pb(dis);
            for(auto [v,w] : adj[u])
                q.push({w+dis,v});
        }
        fo(i,k)
            cout<<dist[n-1][i]<<" ";
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