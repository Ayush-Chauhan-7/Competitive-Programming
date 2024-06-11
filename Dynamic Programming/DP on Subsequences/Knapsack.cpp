    // https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
    
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


    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W+1));
       for(int i=wt[0];i<=W;i++)
            dp[0][i] = val[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int notPick = dp[i-1][j];
                int pick = 0;
                if(wt[i]<=j)
                    pick = val[i] + dp[i-1][j-wt[i]];
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