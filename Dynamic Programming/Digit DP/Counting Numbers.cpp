    // https://cses.fi/problemset/task/2220
    
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
    ll dp[20][10][2][2];

    ll count(string &s, int i, int last, bool zero,  bool tight)
    {
        if(i==s.size())
            return 1;
        if(last!=-1 && dp[i][last][zero][tight]!=-1)
            return dp[i][last][zero][tight];
        int ub = tight? (s[i]-'0'):9;
        ll ans = 0;
        fo(x,ub+1)
        {
            if(x==last && zero==0)
                continue;
            ans += count(s, i+1, x, (zero&&x==0), (tight && x==ub));
        }
        return dp[i][last][zero][tight] = ans;
    }

    void solve()
    {
        ll L,R;
        cin>>L>>R;
        L--;
        memset(dp,-1,sizeof(dp));
        string r = to_string(R);
        ll ans = count(r,0,-1,1,1);
        memset(dp,-1,sizeof(dp));
        if(L>=0)
        {
            string l = to_string(L);
            ans -= count(l ,0,-1,1,1);
        }
        cout<<ans<<endl;
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