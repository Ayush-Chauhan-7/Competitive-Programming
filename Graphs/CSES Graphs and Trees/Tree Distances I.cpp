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

    const int mxN = 2e5;
    vi adj[mxN], f(mxN), g(mxN), h(mxN);
    // f -> max distance in subtree of i
    // g -> max distance
    // h ->  max distance from node i to any node in the subtree rooted at i 
    // excluding the child subtree that contributed to f[i]
    // to_p -> max distance outside subtree of i

    void dfs(ll u=0, ll p=-1)
    {
        for(auto v:adj[u])
        {
            if(v==p)
                continue;
            dfs(v,u);
            if(f[v]+1 > f[u])
            {
                h[u] = f[u];
                f[u] = f[v]+1;
            }
            else if(f[v]+1 > h[u])
                h[u] = f[v]+1;
        }
    }

    void dfs2(ll u=0, ll p=-1, ll to_p=0)
    {
        g[u] = max(f[u],to_p);
        for(auto v:adj[u])
        {
            if(v==p)
                continue;
            if(f[v]+1 == f[u])
                dfs2(v,u, max(to_p,h[u])+1);
            else
                dfs2(v,u, g[u]+1);
        }  
    }

    void solve()
    {
        ll n,u,v;
        cin>>n;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs();
        dfs2();
        fo(i,n)
            cout<<g[i]<<" ";
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