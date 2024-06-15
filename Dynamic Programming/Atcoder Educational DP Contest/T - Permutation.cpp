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

    const int mxN = 3e3, mod = 1e9+7;
    ll dp[mxN][mxN];

    void add(ll &a, ll b)
    {
        a+=b;
        if(a>=mod)
            a-=mod;
    }

    void solve()
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        dp[0][0] = 1;
        fo(i,n-1)
        {
            if(s[i]=='<')
            {
                for(int j=1;j<=i;j++)
                    add(dp[i][j],dp[i][j-1]);
                for(int j=1;j<=i+1;j++)
                    dp[i+1][j] = dp[i][j-1];
            }
            else
            {
                for(int j=i;j>=0;j--)
                    add(dp[i][j],dp[i][j+1]);
                for(int j=i;j>=0;j--)
                    dp[i+1][j] = dp[i][j];
            }
        }
        ll ans = 0;
        fo(i,n)
            add(ans,dp[n-1][i]);
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