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
    const int mod = 1e9+7, mxN = 1e6+1;
    ll dp[mxN][2];

    void solve()
    {
        int n;
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        dp[0][0] = dp[0][1] = 1;
        for(int i=1;i<mxN;i++)
        {
            dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])%mod;
            dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%mod;
        }
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }