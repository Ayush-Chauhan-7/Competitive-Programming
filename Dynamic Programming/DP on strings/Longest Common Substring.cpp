    // https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
    
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


    int longestCommonSubstr (string t1, string t2, int n, int m)
    {
        vector<vector<int>> dp(n,vector<int>(m,0));
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(t1[i]==t2[j])
                {
                    dp[i][j] = 1;
                    if(i>0 && j>0)
                        dp[i][j] += dp[i-1][j-1];
                    maxi = max(dp[i][j],maxi);
                }
            }
        }
        return maxi;
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