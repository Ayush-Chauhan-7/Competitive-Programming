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

    vi fin, vis, scc,coins,dp,viss,groups;
    ll c=0,val=0;

    void dfs(ll u, vector<vi> &adj)
    {
        vis[u] = 1;
        scc[u] = c;
        val += coins[u];
        for(auto v : adj[u])
        {
            if(!vis[v])
                dfs(v,adj);
        }
        fin.pb(u);
    }

    void dfss(ll u, vector<set<ll>> &sccs)
    {
        viss[u] = 1;
        for(auto v: sccs[u])
        {
            if(!viss[v])
                dfss(v,sccs);
            dp[u] = max(dp[u],dp[v]);
        }
        dp[u] += groups[u];
    }

    void solve()
    {
        ll n,m,u,v,ans = 0;
        cin>>n>>m;
        coins.resize(n);
        fo(i,n)
            cin>>coins[i];
        vector<vi> adj(n), adjR(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adjR[v].pb(u);
        }
        vis.assign(n,0);
        scc.resize(n);
        fo(i,n)
            if(!vis[i])
                dfs(i,adj);
        vi x = fin;
        reverse(x.begin(),x.end());
        vis.assign(n,0);
        for(auto i:x)
        {
            if(!vis[i])
            {
                val = 0;
                dfs(i,adjR);
                groups.pb(val);
                c++;
            }
        }
        dp.resize(c);
        viss.assign(c,0);
        vector<set<ll>> sccs(c);
        fo(i,n)
        {
            u = scc[i];
            for(auto j: adj[i])
            {
                v = scc[j];
                if(u!=v)
                    sccs[u].insert(v); 
            }
        }
        fo(i,c)
            if(!viss[i])
                dfss(i,sccs);
        fo(i,c)
            ans = max(ans,dp[i]);
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