    // https://cses.fi/problemset/task/2181
    
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
    const int mod = 1e9+7, mxN=11, mxM=1001;
    ll dp[mxM][mxN][1<<mxN];

    void solve()
    {
        int n, m;
        cin >> n >> m;
    
        dp[0][n][0] = 1; // initially it's like the "0th" column is filled but nothing is sticking into the 1st column
    
        for(int i = 1; i <= m; i++){
    
            for(int mask = 0; mask < (1<<n); mask++)
                dp[i][0][mask] = dp[i-1][n][mask]; // unformed part of ith column is the formed part of the (i-1)th column
    
            for(int j = 1; j <= n; j++){
                for(int mask = 0; mask < (1<<n); mask++){
    
                    bool use = (1<<j-1)&mask;
    
                    if(use){
                        dp[i][j][mask]+=dp[i][j-1][mask-(1<<j-1)]; // placing a horizontal tile on an empty place
                    } else {
                        dp[i][j][mask]+=dp[i][j-1][mask+(1<<j-1)]; // not placing anything on a filled place
                        if(j > 1 && !((1<<j-2)&mask)) 
                            dp[i][j][mask]+=dp[i][j-2][mask]; // placing a vertical tile on 2 empty spaces
                    }
    
                    dp[i][j][mask]%=mod;
    
                }
            }
        }
        cout << dp[m][n][0] << '\n'; // the answer is filling the first m columns with nothing sticking out
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