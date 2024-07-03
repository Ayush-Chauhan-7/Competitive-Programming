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
        vi adj[n], in(n),  out(n), path;
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            in[v]++;
            out[u]++;
        }
        for(int i=1;i<n-1;i++)
        {
            if(in[i]!=out[i])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
        if((out[0]-in[0])!=1 || (in[n-1]-out[n-1])!=1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        stack<ll> st;
        st.push(0);
        while(st.size())
        {
            u = st.top();
            if(in[u]==0 && out[u]==0)
            {
                st.pop();
                path.pb(u);
                continue;
            }
            int x  = adj[u].size()-1;
            v = adj[u][x];
            adj[u].pop_back();
            in[v]--;
            out[u]--;
            st.push(v);
        }
        if (path.size() != (m + 1))
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        reverse(path.begin(),path.end());
        for(auto i:path)
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