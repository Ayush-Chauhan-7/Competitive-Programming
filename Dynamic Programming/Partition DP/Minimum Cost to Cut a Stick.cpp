    // https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
    
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


    int minCost(int N, vector<int>& cuts) {
        int n = cuts.size();
        int mini,steps;
        sort(cuts.begin(),cuts.end());
        vector<int> cost(n+2);
        cost[n+1] = N;
        for(int i=0;i<n;i++)
            cost[i+1] = cuts[i];
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                mini = 1e9;
                for(int k=i;k<=j;k++)
                {
                    steps = cost[j+1] - cost[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(steps,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n];

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