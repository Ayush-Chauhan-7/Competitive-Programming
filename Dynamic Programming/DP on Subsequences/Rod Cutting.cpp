    // https://www.geeksforgeeks.org/problems/rod-cutting0840/1
    
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


    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
            dp[0][i] = i*price[0];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int notPick = dp[i-1][j];
                int pick = INT_MIN;
                if(j>=i+1)
                pick = price[i] + dp[i][j-i-1];
                dp[i][j] = max(pick,notPick);
            }
        }
        return dp[n-1][n];
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