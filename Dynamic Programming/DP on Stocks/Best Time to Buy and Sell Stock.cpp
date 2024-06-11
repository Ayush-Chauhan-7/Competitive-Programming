    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    
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

        int buy = prices[0];

        int ans = 0;
        for(int i=1;i<n;i++) {
            ans = max(ans, prices[i]-buy);

            buy = min(buy, prices[i]);  // update a better buy price
        }

        return ans;
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