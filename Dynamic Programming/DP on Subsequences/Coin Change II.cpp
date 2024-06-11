    // https://leetcode.com/problems/coin-change-ii/description/
    
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


    int change(int sum, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,0));
        for(int i=0;i<=sum;i++)
        {
            if(i%a[0]==0)
                dp[0][i] = 1; 
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                int notPick = dp[i-1][j];
                int pick = 0;
                if(j>=a[i])
                    pick = dp[i][j-a[i]];
                dp[i][j] = pick + notPick;
            }
        }
        int ans = dp[n-1][sum];
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