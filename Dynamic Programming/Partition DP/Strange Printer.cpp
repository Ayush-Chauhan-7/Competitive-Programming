    // https://leetcode.com/problems/strange-printer/
    
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


    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mini = 1e8;
                for(int k=i;k<j;k++)
                    mini = min(dp[i][k] + dp[k+1][j],mini);
                dp[i][j] = mini;
                if(s[i]==s[j])
                    dp[i][j]--;
            }
        }
        return dp[0][n-1];
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