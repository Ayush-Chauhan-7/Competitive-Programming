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

    const int mod = 1e9+7, mxN = 1e5+1, mxM = 101;
    ll dp[mxN][mxM], n, m;

    void solve()
    {
        cin>>n>>m;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        if(a[0]==0)
        {
            fo(i,m+1)
                dp[0][i] = 1;
        }
        else
            dp[0][a[0]] = 1;
        dp[0][0] = 0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==0)
            {
                for(int j=1;j<=m;j++)
                {
                    for(int k=-1;k<=1;k++)
                    {
                        int x = j+k;
                        if(x>=1 && x<=m)
                            dp[i][j] = (dp[i][j]+dp[i-1][x])%mod;
                    }
                }
            }
            else
            {
                for(int k=-1;k<=1;k++)
                {
                    int x = a[i]+k;
                    if(x>=1 && x<=m)
                        dp[i][a[i]] = (dp[i][a[i]]+dp[i-1][x])%mod;
                }
            }
        }
        ll ans = 0;
        fo(i,m+1)
            ans = (ans+dp[n-1][i])%mod;
        cout<<ans<<endl;
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