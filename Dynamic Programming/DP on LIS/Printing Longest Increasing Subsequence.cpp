    // https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
    
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


    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n,1), hash(n);
        int ans=0, lastind;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[i]<1+dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>ans)
            {
                ans = dp[i];
                lastind = i;
            }
        }
        vector<int> lis;
        while(hash[lastind]!=lastind)
        {
            lis.push_back(nums[lastind]);
            lastind = hash[lastind];
        }
        lis.push_back(nums[lastind]);
        reverse(lis.begin(),lis.end());
        return lis;
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