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

    vi vis;

    void solve()
    {
        ll n,m,u,v;
        cin>>n>>m;
        vi adj[n];
        vis.resize(n,-1);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        auto bfs = [&adj,&vis](int src)
        {
            vis[src] = 0;
            queue<int> q;
            q.push(src);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto i: adj[node])
                {
                    if(vis[i]==-1)
                    {
                        vis[i] = 1-vis[node];
                        q.push(i);
                    }
                    else if(vis[i]==vis[node])
                    {
                        cout<<"IMPOSSIBLE"<<endl;
                        exit(0);
                    }
                }
            }
            return false;
        };
        fo(i,n)
        {
            if(vis[i]==-1)
                bfs(i);
        }
        fo(i,n)
            cout<<vis[i]+1<<" ";
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