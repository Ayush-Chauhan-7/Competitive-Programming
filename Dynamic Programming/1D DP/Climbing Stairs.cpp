    // https://leetcode.com/problems/climbing-stairs/
    
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

    int climbStairs(int n) {
        int prev1=1, prev2=0,ans;
        for(int i=1;i<=n;i++)
        {
            ans = prev1;
            if(n>1)
                ans += prev2;
            prev2 = prev1;
            prev1 = ans;
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