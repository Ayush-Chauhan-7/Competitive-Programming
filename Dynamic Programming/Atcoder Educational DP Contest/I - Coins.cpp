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
        ll n; double ans;
        cin>>n;
        vector<double> p(n);
        fo(i,n)
            cin>>p[i];
        vector<vector<double>> dp(n+1,vector<double>(n+1));
        dp[0][0] = 1;
        fo(i,n)
        {
            fo(j,i+1)
            {
                dp[i+1][j+1] += dp[i][j]*p[i];
                dp[i+1][j] += dp[i][j]*(1-p[i]);
            }
        }
        for(int i=((n+1)/2);i<=n;i++)
            ans += dp[n][i];
        cout<<setprecision(10)<<ans<<endl;
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