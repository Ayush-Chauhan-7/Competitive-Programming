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
    int n, m, li, ri, ai;
    ll dp, ps[mxN+1], st[1<<19], lz[1<<19];
    vector<array<int, 2>> ex[mxN];

    void app(int i, ll x) {
        st[i]+=x;
        lz[i]+=x;
    }

    void psh(int i) {
        app(2*i, lz[i]);
        app(2*i+1, lz[i]);
        lz[i]=0;
    }

    void upd(int l1, int r1, ll x, int i=1, int l2=0, int r2=n) {
        if(l1<=l2&&r2<=r1) {
            app(i, x);
            return;
        }
        int m2=(l2+r2)/2;
        psh(i);
        if(l1<=m2)
            upd(l1, r1, x, 2*i, l2, m2);
        if(m2<r1)
            upd(l1, r1, x, 2*i+1, m2+1, r2);
        st[i]=max(st[2*i], st[2*i+1]);
    }

    ll qry(int l1, int r1, int i=1, int l2=0, int r2=n) {
        if(l1<=l2&&r2<=r1)
            return st[i];
        psh(i);
        int m2=(l2+r2)/2;
        return max(l1<=m2?qry(l1, r1, 2*i, l2, m2):0, m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):0);
    }

    void solve()
    {
        cin >> n >> m;
        for(int i=0; i<m; ++i) {
            cin >> li >> ri >> ai;
            ps[li-1]+=ai;
            ps[ri]-=ai;
            ex[ri-1].push_back({li, ai});
            upd(li, ri, -ai);
        }
        for(int i=1; i<n; ++i)
            ps[i]+=ps[i-1];
        for(int i=0; i<n; ++i) {
            upd(i+1, i+1, qry(0, i)+ps[i]);
            for(array<int, 2> a : ex[i])
                upd(a[0], i+1, a[1]);
        }
        cout << qry(0, n);
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