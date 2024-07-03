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

    const ll mxN = 2e5;
    vi dp(mxN), adj[mxN];

    void dfs(int u)
    {
        dp[u] = 1;
        for(auto v : adj[u])
        {
            if(!dp[v])
                dfs(v);
            dp[u] += dp[v];
        }
    }

    void solve()
    {
        ll n,x;
        cin>>n;
        fo(i,n-1)
        {
            cin>>x;
            x--;
            adj[x].pb(i+1);
        }
        dfs(0);
        fo(i,n)
            cout<<dp[i]-1<<" ";
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