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

    const ll M = 1e9+7; 
    ll dp[101][100001];

    void solve()
    {
        int n,k;
        cin>>n>>k;
        vi a(n);
        fo(i,n)
            cin>>a[i];
        dp[0][0]=1;
        for(int i=0; i<n; ++i) {
            for(int j=1; j<=k; ++j)
                dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
            for(int j=0; j<=k; ++j) {
                dp[i+1][j]=dp[i][j];
                if(j-a[i]-1>=0)
                    dp[i+1][j]+=M-dp[i][j-a[i]-1];
                dp[i+1][j]%=M;
            }
        }
        cout << dp[n][k];
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