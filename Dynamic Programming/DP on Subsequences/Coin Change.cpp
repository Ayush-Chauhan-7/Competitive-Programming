    // https://leetcode.com/problems/coin-change/
    
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


    int coinChange(vector<int>& a, int sum) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,0));
        for(int i=0;i<=sum;i++)
        {
            if(i%a[0]==0)
                dp[0][i] = i/a[0]; 
            else
                dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int notPick = dp[i-1][j];
                int pick = 1e9;
                if(j>=a[i])
                    pick = 1 + dp[i][j-a[i]];
                dp[i][j] = min(pick,notPick);
            }
        }
        int ans = dp[n-1][sum];
        if (ans >= 1e9)
            return -1;
        return ans;
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