    // https://leetcode.com/problems/triangle/description/
    
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


    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for(int j=0;j<n;j++)
            dp[n-1][j] = t[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
                dp[i][j] = t[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        }
        return dp[0][0];
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