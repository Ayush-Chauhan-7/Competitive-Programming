    // https://leetcode.com/problems/edit-distance/
    
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

    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int i=0;i<=m;i++)
            dp[0][i] = i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]== s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    int a = 1 + dp[i-1][j-1];
                    int b = 1 + dp[i-1][j];
                    int c = 1 + dp[i][j-1];
                    dp[i][j] = min(a,min(b,c));
                }
            }
        }
        return dp[n][m];
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