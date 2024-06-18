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

    const int mxN = 101, mxK = 1e6+1;
    int n,k,ans;
    int a[mxN];

    void solve()
    {
        cin>>n>>k;
        fo(i,n)
            cin>>a[i];
        vi dp(k+1,1e9);
        dp[0] = 0;
        fo(i,n)
        {
            for(int j=0;j<=k-a[i];j++)
                dp[j+a[i]] = min(dp[j+a[i]], 1 + dp[j]);
        }
        cout<<(dp[k]==1e9?-1:dp[k])<<endl;
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