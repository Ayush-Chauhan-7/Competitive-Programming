    // https://leetcode.com/problems/partition-array-for-maximum-sum/
    
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


    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), maxi = INT_MIN,cost,len,maxii;
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--)
        {
            maxii = INT_MIN;
            maxi = INT_MIN;
            len=0;
            for(int j = i;j<min(n,i+k);j++)
            {
                len++;
                maxii = max(maxii,arr[j]);
                cost = len*maxii + dp[j+1];
                maxi = max(maxi, cost);
            }
            dp[i] = maxi;
        }
        return dp[0];
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