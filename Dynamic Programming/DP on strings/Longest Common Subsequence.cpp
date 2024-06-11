    https://leetcode.com/problems/longest-common-subsequence/description/
    
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

    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(t1[i]==t2[j])
                {
                    dp[i][j] = 1;
                    if(i>0 && j>0)
                        dp[i][j] += dp[i-1][j-1];
                }
                else
                {
                    int p1 = 0, p2 = 0;
                    if(i>0)
                        p1 = dp[i-1][j];
                    if(j>0)
                        p2 = dp[i][j-1];
                    dp[i][j] = max(p1,p2);
                }
            }
        }
        return dp[n-1][m-1];
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