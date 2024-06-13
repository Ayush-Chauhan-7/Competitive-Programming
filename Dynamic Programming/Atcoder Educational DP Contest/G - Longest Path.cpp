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

    vector<vi> graph;
    vi dp;

    ll path(ll u)
    {
        if(!dp[u])
        {
            for(ll v: graph[u])
                dp[u] = max(path(v), dp[u]);
            dp[u]++;
        }
        return dp[u];
    }

    void solve()
    {
        ll n,m,x,y,ans=0;
        cin>>n>>m;
        graph.resize(n);
        dp.resize(n);
        fo(i,m)
        {
            cin>>x>>y;
            x--, y--;
            graph[x].pb(y);
        }
        fo(i,n)
            ans = max(ans, path(i));
        cout<<ans-1<<endl;
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