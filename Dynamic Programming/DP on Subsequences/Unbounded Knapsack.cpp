    // https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
    
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


    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int i=0;i<=W;i++)
            dp[0][i] = (i/wt[0])*val[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int notPick = dp[i-1][j];
                int pick = INT_MIN;
                if(j>=wt[i])
                    pick = val[i] + dp[i][j-wt[i]];
                dp[i][j] = max(pick,notPick);
            }
        }
        return dp[n-1][W];
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