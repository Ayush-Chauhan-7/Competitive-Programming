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

    const int mxN=2e5;
    int n, h[mxN], a[mxN];
    ll ft[mxN+1], dp, ans;

    void upd(int i, ll x) {
        for(; i<=n; i+=i&-i)
            ft[i]=max(ft[i], x);
    }

    ll qry(int i) {
        ll r=0;
        for(; i; i-=i&-i)
            r=max(ft[i], r);
        return r;
    }


    void solve()
    {
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> h[i];
        for(int i=0; i<n; ++i)
            cin >> a[i];
        for(int i=0; i<n; ++i) {
            dp=qry(h[i])+a[i];
            ans=max(dp, ans);
            upd(h[i], dp);
        }
        cout << ans;
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