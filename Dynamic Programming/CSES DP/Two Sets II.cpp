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
    const int mod = 1e9+7;

    void solve()
    {
        int n;
        cin>>n;
        ll sum = n*(n+1)/2;
        if(sum%2)
        {
            cout<<0<<endl;
            return;
        }
        sum/=2;
        vi dp(sum+1);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=sum;j>=i+1;j--)
                dp[j] = (dp[j]+dp[j-i-1])%mod;
        }
        cout<<dp[sum]<<endl;
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