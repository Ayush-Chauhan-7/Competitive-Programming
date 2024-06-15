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

    const int m = 1e9+7, mxN = 3e3+5, mxH = 2e5+5;
    ll fact[mxH], invfact[mxH], dp[mxN];

    long long binpow(long long a, long long b) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    ll binomial(int a, int b)
    {
        if(a<0 || b<0 || a<b)
            return 0;
        return (fact[a]*((invfact[b]*invfact[a-b])%m))%m ;
    }

    void solve()
    {
        int h,w,n;
        cin>>h>>w>>n;
        vp a(n+1);
        fo(i,n)
            cin>>a[i].f>>a[i].s;
        a[n].f = h, a[n].s = w;
        sort(a.begin(),a.end());
        fo(i,n+1)
        {
            dp[i] = binomial(a[i].f+a[i].s-2, a[i].f-1);
            fo(j,i)
            {
                dp[i] -= (dp[j]*binomial((a[i].f-a[j].f)+(a[i].s-a[j].s),a[i].f-a[j].f))%m;
                if(dp[i]<0)
                    dp[i] += m;
            }
        }
        cout<<dp[n]<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        fact[0] = 1, invfact[0] = 1;
        for(int i=1;i<mxH;i++)
        {
            fact[i] = (i*fact[i-1])%m;
            invfact[i] = binpow(fact[i],m-2);
        }
        solve();
        return 0;
    }