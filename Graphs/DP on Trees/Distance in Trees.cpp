    // https://codeforces.com/contest/161/problem/D 
    
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

    const int mxN = 50000, mxK = 501;
    ll n,k,u,v, dp1[mxN][mxK], dp2[mxN][mxK], ans = 0;
    vi adj[mxN];

    void dfs(ll u=0, ll p=-1)
    {
        for(auto v : adj[u])
            if(v!=p)
                dfs(v,u);
        dp1[u][0] = 1;
        for(int dis = 1; dis<=k; dis++)
        {
            for(auto v : adj[u])
                if(v!=p)
                    dp1[u][dis] += dp1[v][dis-1];
        }
    }

    void reroot(ll u=0, ll p=-1)
    {
        fo(i,k+1)
            dp2[u][i] = dp1[u][i];

        if(p!=-1)
        {
            dp2[u][1] += dp2[p][0];
            for(int dis=2;dis<=k;dis++)
            {
                dp2[u][dis] += dp2[p][dis-1];
                dp2[u][dis] -= dp1[u][dis-2];
            }
        }
        for(auto v : adj[u])
        {
            if(v!=p)
                reroot(v,u);
        }
    }

    void solve()
    {
        cin>>n>>k;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        reroot();
        fo(i,n)
            ans += dp2[i][k];
        cout<<ans/2<<endl;
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