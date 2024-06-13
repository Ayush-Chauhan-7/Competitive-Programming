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
        ll n,W, pick, notPick;
        cin>>n>>W;
        vi v(n), w(n), prev(W+1);
        fo(i,n)
            cin>>w[i]>>v[i];
        fo(i,n)
        {
            for(int j=W-w[i];j>=0;j--)
                prev[j+w[i]] = max(v[i] + prev[j], prev[j+w[i]]);
        }
        cout<<prev[W]<<endl;
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