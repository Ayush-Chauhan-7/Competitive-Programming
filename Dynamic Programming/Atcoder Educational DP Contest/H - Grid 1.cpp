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

    const ll mod = 1e9 + 7;

    void solve()
    {
        ll n,m;
        cin>>n>>m;
        char x;
        vector<vi> dp(n,vi(m,0));
        dp[0][0] = 1;
        fo(i,n)
        {
            fo(j,m)
            {
                cin>>x;
                if(x!='#')
                {
                    if(i>0)
                        dp[i][j] += dp[i-1][j];
                    if(j>0)
                        dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }

            }
        }
        cout<<dp[n-1][m-1]<<endl;
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