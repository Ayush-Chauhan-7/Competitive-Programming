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

    const int mod = 1e9+7;

    void solve()
    {
        ll n,k;
        cin>>n>>k;
        vi dp(k+1), a(n);
        fo(i,n)
            cin>>a[i];
        dp[0] = 1;
        fo(j,k+1)
        {
            fo(i,n)
            {
                if(j>=a[i])
                    dp[j] = (dp[j] + dp[j-a[i]])%mod;
            }
        }
        cout<<dp[k]<<endl;
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