    //https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
    
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


    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        if(sum>=arr[0])
            dp[0][arr[0]] = true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(j>=arr[i])
                    take = dp[i-1][j-arr[i]];
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][sum];
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