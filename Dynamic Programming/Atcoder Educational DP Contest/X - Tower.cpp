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

    const int mxN = 1e3, mxW = 2e4+1;
    int w[mxN], v[mxN], s[mxN];
    ll dp[mxW], ans=0;

    void solve()
    {
        int n,i;
        cin>>n;
        vp ind(n);
        fo(i,n)
        {
            cin>>w[i]>>s[i]>>v[i];
            ind[i].f = s[i]+w[i];
            ind[i].s = i;
        }
        sort(ind.begin(),ind.end());
        fo(k,n)
        {
            i = ind[k].s;
            for(int j=s[i];j>=0;j--)
                dp[j+w[i]] = max(dp[j+w[i]] , dp[j] + v[i]);
        }
        fo(i,mxW)
            ans = max(ans, dp[i]);
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