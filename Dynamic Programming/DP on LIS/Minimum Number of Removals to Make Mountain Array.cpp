    // https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
    
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
    
    int LIS(vector<int>& nums, vector<int>& dp1) {
        int n = nums.size();
        vector<int> store;
        store.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > store.back()) {
                store.push_back(nums[i]);
            } else {
                int lb = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();
                store[lb] = nums[i];
            }
            dp1[i] = store.size();
        }
        int ans = store.size();
        return ans;
    }
    
    int LDS(vector<int>& nums, vector<int>& dp2) {
        int n = nums.size();
        vector<int> store;
        store.push_back(nums[n-1]);
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > store.back()) {
                store.push_back(nums[i]);
            } else {
                int lb = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();
                store[lb] = nums[i];
            }
            dp2[i] = store.size();
        }
        int ans = store.size();
        return ans;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int lis = LIS(nums, dp1);
        int lds = LDS(nums, dp2);
        int maxi = -1;
        for (int i = 0; i <n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i]);
            }
        }
        return n - maxi + 1;
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