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
        ll n,m,q,u,v,w;
        cin>>n>>m>>q;
        vector<vi> d(n,vi(n,1e18));
        fo(i,m)
        {
            cin>>u>>v>>w;
            u--,v--;
            d[u][v] = min(d[u][v],w);
            d[v][u] = min(d[v][u],w);
        }
        fo(i,n)
            d[i][i] = 0;
        fo(k,n)
            fo(i,n)
                fo(j,n)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        fo(i,q)
        {
            cin>>u>>v;
            u--,v--;
            cout<< (d[u][v]==1e18? -1:d[u][v]) <<endl;
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