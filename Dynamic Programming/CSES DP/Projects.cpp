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
        ll n;
        cin>>n;
        vector<pair<pair<ll,ll>,ll>> a(n);
        fo(i,n)
            cin>>a[i].f.s>>a[i].f.f>>a[i].s;
        sort(a.begin(),a.end());
        vi dp(n), ends;
        ends.pb(a[0].f.f);
        dp[0] = a[0].s;
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1];
            ll ind = lower_bound(ends.begin(),ends.end(),a[i].f.s)-ends.begin();
            ind--;
            ll prev = 0;
            if(ind>=0)
                prev = dp[ind];
            dp[i] = max(dp[i],a[i].s+prev);
            ends.pb(a[i].f.f);
        }
        cout<<dp[n-1]<<endl;
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