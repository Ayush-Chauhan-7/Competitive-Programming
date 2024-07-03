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

    ll anc[200000][30];

    void solve()
    {
        ll n,q, u, k;
        cin>>n>>q;
        fo(i,n)
        {
            cin>>anc[i][0];
            anc[i][0]--;
        }
        for(int i=1; i<30;i++)
            fo(u,n)
                anc[u][i] = anc[anc[u][i-1]][i-1];
        fo(i,q)
        {
            cin>>u>>k;
            u--;
            fo(i,30)
                if((k>>i)&1)
                    u = anc[u][i];
            cout<<u+1<<endl;
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