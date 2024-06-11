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


    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n);
        for(int i=1;i<n;i++)
        {
            int x = INT_MAX;
            for(int j = i-1; j>= max(i-k,0);j--)
                x = min(x, dp[j] + abs(height[i]-height[j]));
            dp[i] = x;
        }
        return dp[n-1];
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