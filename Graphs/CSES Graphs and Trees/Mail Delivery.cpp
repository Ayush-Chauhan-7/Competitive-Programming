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
        vector<set<ll>> adj(n);
        vi path, deg(n);
        fo(i,m)
        {
            cin>>u>>v;
            u--,v--;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        fo(i,n)
        {
            if(deg[i]%2)
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
        stack<ll> st;
        st.push(0);
        while(!st.empty())
        {
            u = st.top();
            if(deg[u]==0)
            {
                path.pb(u);
                st.pop();
                continue;
            }
            v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            deg[u]--;
            deg[v]--;
            st.push(v);
        }
        if(path.size() != (m+1))
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
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