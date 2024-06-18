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
 
 
    void solve()
    {
        int n,x;
        cin>>n>>x;
        vi w(n), v(n), dp(x+1);
        fo(i,n)
            cin>>w[i];
        fo(i,n)
            cin>>v[i];
        fo(i,n)
        {
            for(int j=x-w[i];j>=0;j--)
                dp[j+w[i]] = max(dp[j]+v[i], dp[j+w[i]]);
        }
        cout<<dp[x]<<endl;
    }
 
    int main()
    {
        ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        solve();
        return 0;
    }