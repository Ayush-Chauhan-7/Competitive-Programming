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
        string s,t;
        cin>>s>>t;
        ll n = s.size();
        ll m = t.size();
        vector<vi> dp(n+1,vi(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        ll i=n,j=m;
        string ans = "";
        while(i>0 && j>0)
        {
            if(s[i-1]==t[j-1])
            {
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
        reverse(ans.begin(),ans.end());
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