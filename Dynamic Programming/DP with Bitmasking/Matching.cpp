    // https://atcoder.jp/contests/dp/tasks/dp_o
    
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
    const int mod = 1e9+7, mxN=21;
    ll a[mxN][mxN], dp[1<<mxN],n;

    void solve()
    {
        cin>>n;
        fo(i,n)
        {
            fo(j,n)
                cin>>a[i][j];
        }
        dp[0] = 1;
        for(int mask=1;mask<(1<<n);mask++)
        {
            int i = __builtin_popcount(mask)-1;
            fo(j,n)
            {
                if((mask>>j & 1) && a[i][j])
                    dp[mask] += dp[mask^(1<<j)];
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
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