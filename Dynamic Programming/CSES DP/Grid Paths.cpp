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

    int a[1001][1001], dp[1001][1001], n;
    const int mod = 1e9+7;

    void solve()
    {
        char x;
        cin>>n;
        fo(i,n)
        {
            fo(j,n)
            {
                cin>>x;
                if(x=='*')
                    a[i][j] = 1;
            }
        }
        dp[0][0] = 1;
        fo(i,n)
        {
            fo(j,n)
            {
                if(a[i][j])
                {
                    dp[i][j] = 0;
                    continue;
                }
                if(i)
                    dp[i][j] += dp[i-1][j];
                dp[i][j]%=mod;
                if(j)
                    dp[i][j] += dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
        cout<<dp[n-1][n-1]<<endl;
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