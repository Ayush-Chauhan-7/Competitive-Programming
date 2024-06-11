    // https://leetcode.com/problems/house-robber-ii/
    
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

    int robb(vector<int>& nums, int start, int end) {
        int p1=nums[start],p2=0,d1,d2;
        for(int i=start+1;i<end;i++)
        {
            d1 = p1;
            d2 = nums[i];
            if(i>1)
                d2 += p2;
            p2 = p1;
            p1 = max(d1,d2);
        }
        return p1;
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int ans1 = robb(nums,0,nums.size()-1);
        int ans2 = robb(nums,1,nums.size());
        return max(ans1,ans2);
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