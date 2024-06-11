    // https://leetcode.com/problems/partition-equal-subset-sum/description/
    
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


    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        int n = nums.size();
        vector<vector<bool>> dp(nums.size(),vector<bool>(halfSum+1,false));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        if(halfSum>=nums[0])
            dp[0][nums[0]] = true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=halfSum;j++)
            {
                int notTake = dp[i-1][j];
                int take = 0;
                if(j>=nums[i])
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][halfSum];
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