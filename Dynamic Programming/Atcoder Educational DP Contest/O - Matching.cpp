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

    const int mod = 1e9 + 7;

    void solve()
    {
        int n, ind;
        cin>>n;
        int a[n][n];
        fo(i,n)
        {
            fo(j,n)
                cin>>a[i][j];
        }
        vi dp(1<<n);
        dp[0] = 1;
        for(int i=1;i<1<<n;i++)
        {
            ind = __builtin_popcount(i)-1;
            fo(j,n)
            {
                if((i>>j & 1) && (a[ind][j]))
                    dp[i] = (dp[i] + dp[i^1<<j])%mod;
            }
        }
        cout<<dp.back()<<endl;
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