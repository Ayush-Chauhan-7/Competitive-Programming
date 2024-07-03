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
        vector<vi> adj(n);
        vi in(n),p(n,-1),ans;
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            in[v]++;
        }
        queue<ll> q;
        auto topSort = [&]()->void
        {
            while(q.size())
            {
                int u = q.front();
                q.pop();
                for(auto v : adj[u])
                {
                    in[v]--;
                    if(!in[v])
                    {
                        p[v] = u;
                        if(v)
                            q.push(v);
                    }
                }
            }
        };
        for(int i=1;i<n;i++)
            if(!in[i])
                q.push(i);
        topSort();
        p[n-1] = -1;
        q.push(0);
        topSort();
        if(p[n-1]==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        ll x = n-1;
        ans.pb(x);
        while(x>0)
        {
            x = p[x];
            ans.pb(x);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i: ans)
            cout<<i+1<<" ";
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