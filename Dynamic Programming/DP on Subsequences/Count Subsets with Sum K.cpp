    // https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
    
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

    int mod = (int)(1e9 + 7);

    int perfectSum(int num[], int n, int sum)
    {
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        dp[0][0] = 1;

        for (int i = 1; i <= sum; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {

                if (num[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i - 1][j]
                               + dp[i - 1][j - num[i - 1]];
                }
                dp[i][j] %= mod;
            }
        }

        return dp[n][sum] % mod;
    }

    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        return 0;
    }