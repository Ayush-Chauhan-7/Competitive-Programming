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
    const int mxN = 5001;
    ll dp[mxN][mxN];

    void solve()
    {
        ll n,sum=0;
        cin>>n;
        vi a(n);
        fo(i,n)
        {
            cin>>a[i];
            sum += a[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(j==i)
                    dp[i][j] = a[i];
                else
                    dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
        cout<<(sum+dp[0][n-1])/2<<endl;
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