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


    void solve()
    {
        ll n,m,u,v;
        cin>>n>>m;
        vi adj[n],p(n,-1),path;
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        queue<int> q;
        p[0] = 0;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v:adj[u])
            {
                if(p[v]==-1)
                {
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        int x = n-1;
        if(p[x]==-1)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            while(x)
            {
                path.pb(x+1);
                x = p[x];
            }
            path.pb(1);
            reverse(path.begin(),path.end());
            cout<<path.size()<<endl;
            for(auto i:path)
                cout<<i<<" ";
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