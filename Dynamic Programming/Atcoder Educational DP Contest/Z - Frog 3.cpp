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

    const int mxN=2e5, mxW=2e4, M=1e9+7;
    int n;
    ll dp, c, h[mxN];

    int qh, qt;
    ll a[mxN], b[mxN];
    void al(ll ai, ll bi) {
        while(qt-qh>=2&&(b[qt-1]-b[qt-2])/(a[qt-2]-a[qt-1])>=(bi-b[qt-1])/(a[qt-1]-ai))
            --qt;
        a[qt]=ai, b[qt]=bi;
        ++qt;
    }
    ll qry(ll xi) {
        while(qt-qh>=2&&a[qh]*xi+b[qh]>=a[qh+1]*xi+b[qh+1])
            ++qh;
        return a[qh]*xi+b[qh];
    }

    void solve()
    {
        cin >> n >> c;
        for(int i=0; i<n; ++i)
            cin >> h[i];
        for(int i=n-2; i>=0; --i) {
            al(h[i+1], dp+h[i+1]*h[i+1]);
            dp=h[i]*h[i]+c+qry(-2*h[i]);
        }
        cout << dp<<endl;
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