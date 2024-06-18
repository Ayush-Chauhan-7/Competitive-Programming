    // https://www.spoj.com/problems/GONE/
    
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

    ll dp[10][82][2];
    vi primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    ll count(ll x)
    {
        string s = to_string(x);
        ll n = s.size(), digit, ub,sum=0,asum=0;
        memset(dp, 0, sizeof(dp));
        sum = n*9;
        dp[0][0][0] = 1;
        fo(i,n)
        {
            digit = s[i]-'0';
            fo(j,sum+1)
            {
                fo(k,2)
                {
                    ub = 9;
                    if(!k)
                        ub = digit;
                    fo(xx,ub+1)
                        dp[i+1][j+xx][k||(xx<ub)] += dp[i][j][k];

                }
            }
        }
        fo(j,sum+1)
        {
            digit = (dp[n][j][0]+dp[n][j][1]);
            if(digit>0 && binary_search(primes.begin(),primes.end(), j))
                asum += digit;
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