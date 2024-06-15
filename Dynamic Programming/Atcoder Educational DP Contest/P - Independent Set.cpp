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
    
    vector<vector<int>> graph;
    ll dp[100001][2];
    const ll mod = 1e9 + 7;

    void dfs(int u, int p)
    {
        dp[u][0] = 1; dp[u][1] = 1;
        for(auto v: graph[u])
        {
            if(v==p)
                continue;
            dfs(v,u);
            dp[u][0] *= (dp[v][0] + dp[v][1])%mod;
            dp[u][0] %= mod;
            dp[u][1] *= dp[v][0];
            dp[u][1] %= mod;
        }
    }

    void solve()
    {
        int n,x,y;
        cin>>n;
        graph.resize(n);
        fo(i,n-1)
        {
            cin>>x>>y;
            x--; y--;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        dfs(0,-1);
        cout<<(dp[0][0]+dp[0][1])%mod<<endl;
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