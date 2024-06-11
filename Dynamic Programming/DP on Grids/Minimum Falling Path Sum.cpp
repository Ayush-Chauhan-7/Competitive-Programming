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


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int> > dp(n, vector<int>(n, 0));
        dp[0] = matrix[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a1 = INT_MAX, a3 = INT_MAX;
                int a2 = dp[i-1][j];
                if(j>0)
                    a1 = dp[i-1][j-1];
                if(j<n-1)
                    a3 = dp[i-1][j+1];
                dp[i][j] = matrix[i][j] + min(a1,min(a2,a3));
            }
        }
        int x = *min_element(dp[n-1].begin(),dp[n-1].end());
        return x;
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