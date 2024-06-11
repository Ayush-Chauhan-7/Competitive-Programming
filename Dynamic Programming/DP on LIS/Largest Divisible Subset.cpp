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


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1)
            return nums;
        vector<int> dp(n,0), hash(n);
        int ans=0, lastind=0;
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0) && dp[i]<1+dp[j])
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
        for(int i=0;i<=ans;i++)
        {
            lis.push_back(nums[lastind]);
            lastind = hash[lastind];
        }
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