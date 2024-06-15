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

    const int mxN=1e5;
    int n, M, uu, vv;
    ll dp[mxN], ans[mxN];
    vector<int> adj[mxN];

    void dfs1(int u=0, int p=-1) {
        dp[u]=1;
        for(int v : adj[u]) {
            if(v==p)
                continue;
            dfs1(v, u);
            dp[u]=dp[u]*dp[v]%M;
        }
        dp[u]=(dp[u]+1)%M;
    }

    void dfs2(int u=0, int p=-1, ll pd=1) {
        vector<ll> pp, sp;
        pp.push_back(1);
        for(int v : adj[u]) {
            if(v==p)
                continue;
            pp.push_back(dp[v]);
            sp.push_back(dp[v]);
        }
        sp.push_back(1);
        for(int i=1; i<pp.size(); ++i)
            pp[i]=pp[i]*pp[i-1]%M;
        for(int i=sp.size()-2; i>=0; --i)
            sp[i]=sp[i]*sp[i+1]%M;
        ans[u]=pp.back()*pd%M;
        int i=0;
        for(int v : adj[u]) {
            if(v==p)
                continue;
            dfs2(v, u, (pp[i]*sp[i+1]%M*pd+1)%M);
            ++i;
        }
    }

    void solve()
    {
        cin >> n >> M;
        for(int i=0; i<n-1; ++i) {
            cin >> uu >> vv;
            --uu; --vv;
            adj[uu].push_back(vv);
            adj[vv].push_back(uu);
        }
        dfs1();
        dfs2();
        for(int i=0; i<n; ++i)
            cout << ans[i] << "\n";
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