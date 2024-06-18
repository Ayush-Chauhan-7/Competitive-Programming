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
    ll dp[501][501];

    void solve()
    {
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(i==j)
                    continue;
                dp[i][j] = 1e9;
                for(int k=1;k<i;k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i-k][j] + dp[k][j]);
                for(int k=1;k<j;k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-k] + dp[i][k]);
            }
        }
        cout<<dp[a][b]<<endl;
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