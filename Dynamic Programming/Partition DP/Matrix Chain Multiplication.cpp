    // https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
    
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

    int matrixMultiplication(int n, int arr[])
    {
        int mini,steps;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                mini = 1e9;
                for(int k=i;k<j;k++)
                {
                    steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(steps,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
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