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

    const int mod = 1e9+7,mxN=1e6+1;
    ll dp[mxN];

    void solve()
    {
        int n;
        cin>>n;
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=min(i,6);j++)
                dp[i] = (dp[i]+dp[i-j])%mod;
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
        solve();
        return 0;
    }