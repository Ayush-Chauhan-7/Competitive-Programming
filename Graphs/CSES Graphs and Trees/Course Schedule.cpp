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
        vi adj[n], in(n), ord;
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            in[v]++;
        }
        queue<ll>  q;
        fo(i,n)
            if(!in[i])
                q.push(i);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ord.pb(u);
            for(auto v : adj[u])
            {
                in[v]--;
                if(!in[v])
                    q.push(v);
            }
        }
        if(ord.size()==n)
            fo(i,n)
                cout<<ord[i]+1<<" ";
        else
            cout<<"IMPOSSIBLE"<<endl;
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