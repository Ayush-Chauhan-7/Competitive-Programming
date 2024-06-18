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
    const int mod = 1000000007;
    ll dp[51][51][51][51][2];

    void add(ll &a, ll b)
    {
        a += b;
        if(a>=mod)
            a-=mod;
    }

    ll count(ll number)
    {
        string s = to_string(number);
        memset(dp, 0, sizeof(dp));
        ll n = s.size(), ub,digit, ans=0;
        dp[0][0][0][0][0] = 1;
        fo(i,n)
        {
            fo(c3,n)
            {
                fo(c6,n)
                {
                    fo(c9,n)
                    {
                        fo(k,2)
                        {
                            digit = s[i]-'0';
                            ub = 9;
                            if(!k)
                                ub = digit;
                            fo(x,ub+1)
                            {
                                if(x==3)
                                    add(dp[i+1][c3+1][c6][c9][k||(ub<x)] , dp[i][c3][c6][c9][k]);
                                if(x==6)
                                    add(dp[i+1][c3][c6+1][c9][k||(ub<x)] , dp[i][c3][c6][c9][k]);
                                if(x==9)
                                    add(dp[i+1][c3][c6][c9+1][k||(ub<x)] , dp[i][c3][c6][c9][k]);
                                add(dp[i+1][c3][c6][c9][k||(ub<x)] , dp[i][c3][c6][c9][k]);
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=50;i++)
        {
            add(ans, dp[n][i][i][i][0]);
            add(ans, dp[n][i][i][i][1]);
        }
        return ans;
    }

    void solve()
    {
        ll l,r;
        cin>>l>>r;
        l--;
        cout<<count(r)-count(l)<<endl;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll t;
        cin>>t;
        while(t--)
            solve();
        return 0;
    }