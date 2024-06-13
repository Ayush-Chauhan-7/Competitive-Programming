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
        ll n,k;
        cin>>n>>k;
        vi h(n), dp(n,1e9);
        dp[0] = 0;
        fo(i,n)
            cin>>h[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=max(0ll,i-k);j--)
                dp[i] = min(dp[i], abs(h[i]-h[j])+dp[j]);
        }
        cout<<dp[n-1]<<endl;
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