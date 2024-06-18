    // https://codeforces.com/contest/16/problem/E
    
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

    const int mxN = 18;
    double dp[1<<18], pr[mxN][mxN];

    void solve()
    {
        int n;
        cin>>n;
        fo(i,n)
        {
            fo(j,n)
                    cin>>pr[i][j];
        }
        ll start = (1<<n) - 1;
        dp[start] = 1.0;
        for(int mask=start;mask>0;mask--)
        {
            int alive = __builtin_popcount(mask);
            if(alive==1) continue;
            double deno = (alive*(alive-1))/2;
            double prob = dp[mask]/deno ;
            fo(j,n)
            {
                if(mask>>j & 1)
                {
                    for(int k=j+1;k<n;k++)
                    {
                        if(mask>>k & 1)
                        {
                            dp[mask^(1<<k)] += prob*pr[j][k];
                            dp[mask^(1<<j)] += prob*pr[k][j];
                        }
                    }
                }
            }
        }
        fo(i,n)
            cout<<setprecision(7)<<dp[1<<i]<<" ";
        cout<<endl;
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