    // https://leetcode.com/problems/target-sum/description/
    
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


    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x: nums)
            sum += x;
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int s1 = (sum - target)/2;
        int ans = subsetCount(nums,s1);
        return ans;
    }
    
    int subsetCount(vector<int>& nums, int s1){
        int n = nums.size();
        int t[n+1][s1+1];
        t[0][0] = 1;
        for(int i=1;i<s1+1;i++)
            t[0][i] = 0;
        for(int i=1;i<n+1;i++)
            for(int j=0;j<s1+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
            }
        
        return t[n][s1];
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