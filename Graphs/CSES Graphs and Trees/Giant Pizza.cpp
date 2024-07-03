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

    vi fin, vis, scc;
    int c=1;

    void dfs(ll u, vector<vi> &adj)
    {
        vis[u] = 1;
        scc[u] = c;
        for(auto v : adj[u])
        {
            if(!vis[v])
                dfs(v,adj);
        }
        fin.pb(u);
    }

    void solve()
    {
        ll n,m,u,v,nu,nv;
        cin>>m>>n;
        n*=2;
        string s;
        vector<vi> adj(n), adjR(n);
        fo(i,m)
        {
            char a,b;
            cin>>a>>u>>b>>v;
            u--,v--;
            u*=2;
            if(a=='-')
                u ^= 1;
            v *= 2;
            if(b=='-')
                v  ^= 1;
            nu = u ^ 1;
            nv = v ^ 1;
            adj[nu].pb(v);
            adj[nv].pb(u);
            adjR[u].pb(nv);
            adjR[v].pb(nu);
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
                dfs(i,adjR);
                c++;
            }
        }
        string ans = "";
        for(int i=0;i<n-1;i+=2)
        {
            if(scc[i]==scc[i+1])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
            if(scc[i]>scc[i+1])
                ans += '+';
            else
                ans += '-';
        }
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