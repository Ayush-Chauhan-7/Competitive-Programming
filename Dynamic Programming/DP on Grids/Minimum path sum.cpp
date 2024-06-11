    // https://leetcode.com/problems/minimum-path-sum/description/
    
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


    int minPathSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = a[i][j];
                if(i>0 && j>0)
                    dp[i][j] += min(dp[i-1][j],dp[i][j-1]);
                else if(i>0)
                    dp[i][j] += dp[i-1][j];
                else if(j>0)
                    dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
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