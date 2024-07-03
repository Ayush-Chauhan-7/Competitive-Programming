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

    vi fin, vis;

    void dfs(ll u, vector<vi> &adj)
    {
        vis[u] = 1;
        for(auto v : adj[u])
        {
            if(!vis[v])
                dfs(v,adj);
        }
        fin.pb(u);
    }

    void solve()
    {
        ll n,m,u,v;
        cin>>n>>m;
        vector<vi> adj(n), adjR(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adjR[v].pb(u);
        }
        vis.assign(n,0);
        fo(i,n)
            if(!vis[i])
                dfs(i,adj);
        vi x = fin,ans;
        reverse(x.begin(),x.end());
        vis.assign(n,0);
        for(auto i:x)
        {
            if(!vis[i])
            {
                ans.pb(i+1);
                dfs(i,adjR);
            }
        }
        if(ans.size()==1)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
            cout<<ans[1]<<" "<<ans[0]<<endl;
        }
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