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
 
    ll dp[5001][5001];
 
    void solve()
    {
        string a,b;
        cin>>a>>b;
        int n = a.size(), m = b.size(),c1,c2,c3;
        fo(i,n+1)
            dp[i][0] = i;
        fo(i,m+1)
            dp[0][i] = i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    c1 = 1 + dp[i-1][j];
                    c2 = 1 + dp[i-1][j-1];
                    c3 = 1 + dp[i][j-1];
                    dp[i][j] = min(min(c1,c2),c3);
                }
            }
        }
        cout<<dp[n][m]<<endl;
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