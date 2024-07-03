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
    ll n,q,u,v,anc[mxN][18], d[mxN], pref[mxN], c;
    vi adj[mxN];

    void binary_lifting(ll u=0, ll p=-1)
    {
        anc[u][0] = p;
        for(int i=1;i<18;i++)
            if(anc[u][i-1]!=-1)
                anc[u][i] = anc[anc[u][i-1]][i-1];
            else
                anc[u][i] = -1;
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            d[v] = d[u] + 1;
            binary_lifting(v,u);
        }
    }

    ll lift_node(ll u, ll k)
    {
        if(d[u]<k)
            return -1;
        ll x = u;
        for(int i=17;i>=0;i--)
            if((k>>i)&1)
                x = anc[x][i];
        return x;
    }

    ll lca(ll u, ll v)
    {
        if(d[v]>d[u])
            swap(v,u);
        u = lift_node(u,d[u]-d[v]);
        if(u==v)
            return u;
        for(int i=17;i>=0;i--)
        {
            if(anc[u][i]!=anc[v][i])
            {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }

    void dfs(ll u=0, ll p=-1)
    {
        for(auto v : adj[u])
        {
            if(v==p)
                continue;
            dfs(v,u);
            pref[u] += pref[v];
        }
    }

    void solve()
    {
        cin>>n>>q;
        fo(i,n-1)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        binary_lifting();
        fo(i,q)
        {
            cin>>u>>v;
            u--,v--;
            c = lca(u,v);
            pref[u]++;
            pref[v]++;
            pref[c]--;
            if(anc[c][0]!=-1)
                pref[anc[c][0]]--;
        }
        dfs();
        fo(i,n)
            cout<<pref[i]<<" ";     
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