    // https://www.spoj.com/problems/RAONE/
    
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

    ll dp[10][81][81][2];

    ll count(ll x)
    {
        string s = to_string(x);
        ll n = s.size(), digit, ub,asum=0;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        fo(i,n)
        {
            digit = s[i]-'0';
            fo(j,81)
            {
                fo(jj,81)
                {
                    fo(k,2)
                    {
                        ub = 9;
                        if(!k)
                            ub = digit;
                        if(i%2)
                        {
                            fo(xx,ub+1)
                                dp[i+1][j+xx][jj][k||(xx<ub)] += dp[i][j][jj][k];
                        }
                        else
                        {
                            fo(xx,ub+1)
                                dp[i+1][j][jj+xx][k||(xx<ub)] += dp[i][j][jj][k];
                        }

                    }
                }
            }
        }
        for(int j=1;j<=80;j++)
        {
            digit = (dp[n][j][j-1][0]+dp[n][j][j-1][1]);
            asum+=digit;
        }
        return asum;
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