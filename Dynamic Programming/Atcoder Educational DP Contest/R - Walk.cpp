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

    const int mxN=50, M=1e9+7;
    int n;
    ll k;

    struct mat {
        ll a[mxN][mxN];
        mat operator*(const mat &o) const {
            mat r={};
            for(int i=0; i<n; ++i)
                for(int k=0; k<n; ++k)
                    for(int j=0; j<n; ++j)
                        r.a[i][j]=(r.a[i][j]+a[i][k]*o.a[k][j])%M;
            return r;
        }
    } b, r;


    void solve()
    {
        cin >> n >> k;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> b.a[i][j];
        for(int i=0; i<n; ++i)
            r.a[i][i]=1;
        while(k) {
            if(k&1)
                r=r*b;
            b=b*b;
            k/=2;
        }
        ll ans=0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                ans+=r.a[i][j];
        cout << ans%M;
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