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
        ll n;
        cin>>n;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        vector<vi> dp(n+1, vi(n+1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n;j++)
                dp[i][j] = max(a[i] - dp[i+1][j], a[j-1] - dp[i][j-1]);
        }
        cout<<dp[0][n]<<endl;
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