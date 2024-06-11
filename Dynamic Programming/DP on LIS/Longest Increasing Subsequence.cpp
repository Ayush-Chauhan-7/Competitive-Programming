    // https://leetcode.com/problems/longest-increasing-subsequence/description/
    
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


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.pb(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
                temp.pb(nums[i]);
            else
            {
                auto ind = lower_bound(temp.begin(),temp.end(),nums[i]);
                temp[int(ind-temp.begin())] = nums[i];
            }
        }
        return temp.size();
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