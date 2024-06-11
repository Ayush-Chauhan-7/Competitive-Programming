    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

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


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<pair<int,int>> dp(n+2,{0,0});
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    int d1 = -prices[i] + dp[i+1].first;
                    int d2 = dp[i+1].second;
                    dp[i].second = max(d1,d2);
                }
                else
                {
                    int d1 = prices[i] + dp[i+2].second;
                    int d2 = dp[i+1].first;
                    dp[i].first = max(d1,d2);
                }
                
            }
        }
        return dp[0].second;
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