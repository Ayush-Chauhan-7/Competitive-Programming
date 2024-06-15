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
    const int mxN = 1e4, mod = 1e9+7;
    ll dp[mxN][100][2];

    void add(ll &a, ll b)
    {
        a += b;
        if(a>=mod)
            a-=mod;
    }

    void solve()
    {
        string s;
        cin>>s;
        int d, ub, digit;
        cin>>d;
        int n = s.size();
        dp[0][0][0] = 1;
        fo(i,n)
        {
            digit = s[i] - '0';
            fo(j,d)
            {
                fo(k,2)
                {
                    ub = 9;
                    if(!k)
                        ub = digit;
                    fo(x,ub+1)
                        add(dp[i+1][(j+x)%d][k||(x<digit)], dp[i][j][k]);
                }
            }
        }
        int ans = (dp[n][0][0] + dp[n][0][1]) % mod;
        ans = (ans + mod - 1) % mod;
        cout << ans << "\n";
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